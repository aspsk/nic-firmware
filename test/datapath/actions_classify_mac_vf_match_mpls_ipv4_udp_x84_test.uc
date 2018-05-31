;TEST_INIT_EXEC nfp-reg mereg:i32.me0.XferIn_32=0x0
;TEST_INIT_EXEC nfp-reg mereg:i32.me0.XferIn_33=0x0
;TEST_INIT_EXEC nfp-reg mereg:i32.me0.XferIn_34=0xdeadbeef
;TEST_INIT_EXEC nfp-reg mereg:i32.me0.XferIn_35=0xdeadbeef

#include "pkt_mpls_ipv4_udp_x84.uc"
#include <global.uc>
#include "actions_harness.uc"
#include <actions.uc>
#include "actions_classify_veb_insertion.uc"


.reg expected_pv_broadcast
.reg key[2]
.reg action[2]
.reg vlan_id

move(key[0], 0x22330fff)
move(key[1], 0x44556677)
move(action[0], 0xeeffc000)
move(action[1], 0xefbeadde)

move(expected_pv_broadcast, NULL_VLAN<<BF_L(PV_VLAN_ID_bf))

veb_entry_insert(key, action, continue#)
continue#:


alu[vlan_id, --, B, 0]
#define_eval T_IND_INC 0

local_csr_wr[T_INDEX, (32 * 4)]
immed[__actions_t_idx, (32 * 4)]

test_assert_equal($__actions[0], 0x0)
test_assert_equal($__actions[1], 0x0)

alu[__actions_t_idx, t_idx_ctx, OR, &$__actions[0], <<2]
nop
local_csr_wr[T_INDEX, __actions_t_idx]
nop
nop
nop

__actions_mac_classify(pkt_vec, discards_filter_mac#)

test_assert_equal(pkt_vec[PV_VLAN_wrd], expected_pv_broadcast)

test_assert_equal($__actions[0], 0xc0ffee)
test_assert_equal($__actions[1], 0xdeadbeef)

test_assert_equal(*$index++, 0xc0ffee)
test_assert_equal(*$index++, 0xdeadbeef)

test_pass()

discards_filter_mac#:
error_map_fd#:
lookup_not_found#:
test_fail()