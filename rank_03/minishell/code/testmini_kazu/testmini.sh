TESTFILE="test_exec"

../minishell < ${TESTFILE} 2>&1 | grep -v 'minishell>' > out_mini

bash < ${TESTFILE} > out_bash 2>&1

diff --suppress-common-lines out_mini out_bash > out_diff
