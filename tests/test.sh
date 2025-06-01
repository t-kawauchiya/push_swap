#!/bin/bash

# push_swap_test

PUSH_SWAP_BIN="./push_swap"
TMP_DIR="./tests/tmp_test"
CHECKER="./checker"
PERFORMANCE_TEST="./tests/performance_test.sh"
rm -rf "$TMP_DIR" && mkdir -p "$TMP_DIR"

# ---------- 1. helper functions ----------
#
run_case() {
  local title="$1"; shift
  local args=("${@}")

  printf 'Test %s:\n' "$title"

  ${PUSH_SWAP_BIN} ${args[@]} | tee /dev/tty | ${CHECKER} ${args[@]}
}

# run_expect_fail() {
#   local title="$1"; shift
#   if "$PUSH_SWAP_BIN" "$@" 2>/dev/null; then
#     printf 'Test %s: %b\n' "$title" "$NG"
#     printf ' - expected failure but succeeded'; return 1
#   else
#     printf 'Test %s: %b\n' "$title" "$OK"; return 0;
#   fi
# }

STATUS=0

# ---------- 3. normal equivalence-class cases ----------
run_case "element num = 1"\
  "10000"
run_case "input error: {\"a1\"}"\
  "a1"
run_case "element num = 2, {10000, 20000}"\
  "10000" "20000"
run_case "expand args: {\"10000 20000\"}"\
  "10000 20000"
run_case "expand args: {\"  10000 \n20000  \"}"\
  "  10000 
20000  "
run_case "element num = 2, {20000, 10000}"\
  "20000" "10000"
run_case "element num = 3, {1,2,3}"\
  "10000" "20000" "30000"
run_case "element num = 3, {1,3,2}"\
  "1" "3" "2"
run_case "element num = 3, {2,1,3}"\
  "2" "1" "3"
run_case "element num = 3, {2,3,1}"\
  "2" "3" "1"
run_case "element num = 3, {3,1,2}"\
  "3" "1" "2"
run_case "element num = 3, {3,2,1}"\
  "3" "2" "1"
run_case "element num = 4"\
  "10000" "20000" "30000" "40000"
run_case "element num = 4"\
  "101" "1" "111" "11" "10"
bash $PERFORMANCE_TEST

# ---------- 5. invalid-command case ----------
# run_expect_fail "invalid command (exit ~127)"\

# ---------- 6. cleanup & exit ----------
exit $STATUS 
