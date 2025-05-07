

### Category 1: Basic Variable Expansion (`$`)

*   **Case 1.1: Unset Variable**
    *   Command: `echo $NON`
    *   Bash: (empty line)
    *   Expected Minishell: (empty line) - Tests expansion to empty string.
*   **Case 1.2: Variable next to text**
    *   Command: `echo foo$USER bar`
    *   Bash: `foojiepark bar`
    *   Expected Minishell: `foojiepark bar` - Tests concatenation.
*   **Case 1.3: Variable next to text (other side)**
    *   Command: `echo $USERfoo bar`
    *   Bash: `bar` (tries to expand `$USERfoo`, which is likely unset)
    *   Expected Minishell: `bar` - Tests variable name parsing.
*   **Case 1.4: Multiple Variables**
    *   Command: `echo $USER$HOME`
    *   Bash: `jiepark/home/jiepark`
    *   Expected Minishell: `jiepark/home/jiepark` - Tests consecutive expansion.
*   **Case 1.5: Variable as command (valid path)**
    *   Command: `VAR=/bin/ls ; $VAR`
    *   Bash: (output of ls)
    *   Expected Minishell: (output of ls) - Tests execution after expansion.
*   **Case 1.6: Variable as command (invalid command)**
    *   Command: `VAR=hello ; $VAR`
    *   Bash: `hello: command not found`
    *   Expected Minishell: `hello: command not found` - Tests error handling.
*   **Case 1.7: Variable as command (unset)**
    *   Command: `unset VAR ; $VAR`
    *   Bash: (no output, new prompt)
    *   Expected Minishell: (no output, new prompt) - Tests empty command execution (should succeed silently).
*   **Case 1.8: Special Variable `$?` (simple)**
    *   Command: `ls /nonexistent_file ; echo $?`
    *   Bash: `ls: cannot access...` (or similar error), then `2` (or other non-zero code)
    *   Expected Minishell: Error message, then the correct non-zero exit code.
*   **Case 1.9: Special Variable `$$` (PID)**
    *   Command: `echo $$`
    *   Bash: (PID of the bash process)
    *   Expected Minishell: (PID of the minishell process)

---

### Category 2: Basic Wildcard Expansion (`*`)

*   **Case 2.1: Simple Match**
    *   Command: `echo *.txt`
    *   Bash: `a.txt d e.txt`
    *   Expected Minishell: `a.txt d e.txt` - Tests basic globbing.
*   **Case 2.2: No Match**
    *   Command: `echo *.pdf`
    *   Bash: `*.pdf` (literal string)
    *   Expected Minishell: `*.pdf` - Tests behavior when no files match.
*   **Case 2.3: Multiple Matches**
    *   Command: `echo *`
    *   Bash: `a.txt b.log c d e.txt`
    *   Expected Minishell: `a.txt b.log c d e.txt` - Tests matching multiple files.
*   **Case 2.4: Wildcard as command (potential issue)**
    *   Command: `*`
    *   Bash: Tries to execute the first file found (e.g., `a.txt: command not found` or executes if it's a script).
    *   Expected Minishell: Should likely give `*: command not found` or similar, unless a file is executable. Needs careful handling.

---

### Category 3: Quote Removal and Interaction with `$`

*   **Case 3.1: Single Quotes block `$`**
    *   Command: `echo '$USER'`
    *   Bash: `$USER`
    *   Expected Minishell: `$USER` - Tests suppression of expansion.
*   **Case 3.2: Double Quotes allow `$`**
    *   Command: `echo "$USER"`
    *   Bash: `jiepark`
    *   Expected Minishell: `jiepark` - Tests expansion within double quotes.
*   **Case 3.3: Empty Quotes**
    *   Command: `echo "" ''`
    *   Bash: (empty line) (two empty arguments result in one empty line from echo)
    *   Expected Minishell: (empty line) - Tests handling of empty strings after quote removal.
*   **Case 3.4: Adjacent Quotes**
    *   Command: `echo 'he'llo" wo"rld`
    *   Bash: `helloworld`
    *   Expected Minishell: `helloworld` - Tests concatenation after quote removal.
*   **Case 3.5: Variable containing space (unquoted)**
    *   Command: `VAR="hello world" ; echo $VAR`
    *   Bash: `hello world` (echo receives two arguments: "hello" and "world")
    *   Expected Minishell: `hello world` - Tests word splitting after expansion.
*   **Case 3.6: Variable containing space (quoted)**
    *   Command: `VAR="hello world" ; echo "$VAR"`
    *   Bash: `hello world` (echo receives one argument: "hello world")
    *   Expected Minishell: `hello world` - Tests preservation of spaces within double quotes.
*   **Case 3.7: Unset variable in quotes**
    *   Command: `echo "$NON"`
    *   Bash: (empty line)
    *   Expected Minishell: (empty line) - Tests expansion to empty string within quotes.
*   **Case 3.8: Variable next to text in quotes**
    *   Command: `echo "foo${USER}bar"` (using braces for clarity)
    *   Bash: `foojieparkbar`
    *   Expected Minishell: `foojieparkbar` - Tests expansion and concatenation within quotes.

---

### Category 4: Quote Removal and Interaction with `*`

*   **Case 4.1: Single Quotes block `*`**
    *   Command: `echo '*.txt'`
    *   Bash: `*.txt`
    *   Expected Minishell: `*.txt` - Tests suppression of globbing.
*   **Case 4.2: Double Quotes block `*`**
    *   Command: `echo "*.txt"`
    *   Bash: `*.txt`
    *   Expected Minishell: `*.txt` - Tests suppression of globbing.
*   **Case 4.3: Partial Quoting**
    *   Command: `echo a*.t'xt'`
    *   Bash: `a.txt` (globbing happens on `a*.t`, then `'xt'` is appended)
    *   Expected Minishell: `a.txt` - Tests complex interaction.
*   **Case 4.4: Wildcard from Variable (unquoted)**
    *   Command: `VAR="*.txt" ; echo $VAR`
    *   Bash: `*.txt` (Word splitting happens, but globbing does *not* happen on the result of variable expansion)
    *   Expected Minishell: `*.txt` - Crucial test: globbing doesn't re-trigger.
*   **Case 4.5: Wildcard from Variable (quoted)**
    *   Command: `VAR="*.txt" ; echo "$VAR"`
    *   Bash: `*.txt`
    *   Expected Minishell: `*.txt` - Quotes prevent splitting and globbing.

---

### Category 5: Combined and Complex Cases

*   **Case 5.1: Variable and Wildcard (unquoted)**
    *   Command: `echo $USER*`
    *   Bash: (Expands `$USER` to `jiepark`, then tries to glob `jiepark*`. If no match, prints `jiepark*`, otherwise matching files).
    *   Expected Minishell: Same as bash. Tests expansion then globbing.
*   **Case 5.2: Variable and Wildcard (quoted)**
    *   Command: `echo "$USER*"`
    *   Bash: `jiepark*` (Variable expands, `*` is literal).
    *   Expected Minishell: `jiepark*` - Tests expansion allowed, globbing suppressed.
*   **Case 5.3: Unset Variable and Wildcard (unquoted)**
    *   Command: `echo $NON*`
    *   Bash: `a.txt b.log c d e.txt` (Expands `$NON` to `""`, resulting in `echo *`, which globs).
    *   Expected Minishell: `a.txt b.log c d e.txt` - Tests empty expansion followed by globbing.
*   **Case 5.4: Unset Variable and Wildcard (quoted)**
    *   Command: `echo "$NON*"`
    *   Bash: `*` (Expands `$NON` to `""` inside quotes, leaving literal `*`).
    *   Expected Minishell: `*` - Tests empty expansion inside quotes.
*   **Case 5.5: Expansion results in empty command argument**
    *   Command: `ls $NON`
    *   Bash: (output of ls for current directory, as `ls` with no args)
    *   Expected Minishell: (output of ls) - Tests command receiving zero arguments after expansion.
*   **Case 5.6: Expansion results in empty string for redirection**
    *   Command: `echo test > $NON`
    *   Bash: `bash: $NON: ambiguous redirect`
    *   Expected Minishell: Error message about ambiguous redirect. - Tests error handling for redirections.
*   **Case 5.7: Expansion results in multiple args for redirection**
    *   Command: `VAR="a b" ; echo test > $VAR`
    *   Bash: `bash: $VAR: ambiguous redirect`
    *   Expected Minishell: Error message about ambiguous redirect. - Tests error handling.
*   **Case 5.8: Quoted empty string concatenation**
    *   Command: `echo ""hello""world''`
    *   Bash: `helloworld`
    *   Expected Minishell: `helloworld` - Tests removal and concatenation.
*   **Case 5.9: `$?` within quotes**
    *   Command: `false ; echo "Exit status: $?"`
    *   Bash: `Exit status: 1`
    *   Expected Minishell: `Exit status: 1` - Tests `$?` expansion within double quotes.
*   **Case 5.10: `$?` within single quotes**
    *   Command: `false ; echo 'Exit status: $?'`
    *   Bash: `Exit status: $?`
    *   Expected Minishell: `Exit status: $?` - Tests `$?` suppression within single quotes.

