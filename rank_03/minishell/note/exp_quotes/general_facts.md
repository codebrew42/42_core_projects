jiepark:~$ mkdir jiepark1,2,3
jiepark:~$ ls
228.zip	  en.subjectminishell.pdf  jiepark1,2,3	  unnamed.jpg
42_temp	  final_temp_42		  minishell-main
en.norm.pdf  IMG_2488.JPG		  minishell-main.zip
jiepark:~$ mkdir jiepark4

jiepark:~$ ls '$USER*'
ls: cannot access '$USER*': No such file or directory
jiepark:~$ ls "$USER*"
ls: cannot access 'jiepark*': No such file or directory
jiepark:~$ ls $USER*
jiepark1,2,3:

jiepark4:
jiepark:~$ echo $USER* =>expand
jiepark1,2,3 jiepark4
jiepark:~$ echo "$USER*" =>expand
jiepark*
jiepark:~$ echo '$USER*' =>not expand
$USER*

jiepark:~$ echo '"$USER*"'
"$USER*"

# existing files (includes $USER)
```
jiepark:~$ ls
228.zip	  en.subjectminishell.pdf  jiepark1,2,3	minishell-main.zip
42_temp	  final_temp_42		  jiepark4		  unnamed.jpg
en.norm.pdf  IMG_2488.JPG		  minishell-main
```

## no quote
```
jiepark:~$ echo $USER*
jiepark1,2,3 jiepark4

jiepark:~$ ls $USER*
jiepark1,2,3:

jiepark4:
```

# only single quote
```
jiepark:~$ echo '$USER*' => not expand
$USER*
jiepark:~$ ls '$USER*' => not expand
ls: cannot access '$USER*': No such file or directory
```

## only double quote
```
jiepark:~$ ls "$USER*" => expand
ls: cannot access 'jiepark*': No such file or directory
jiepark:~$ echo "$USER*" => expand
jiepark*
```

## nested1 : single quote nested in double quote
```
echo "'$USER*'" => expand
	res: 'jiepark*';
ls "'$USER*'" => expand
	res: ls: cannot access ''\''jiepark*'\''': No such file or directory
```

## nested2 : double quote nested in single quote
```
echo '"$USER*"' => no expand
	res: "$USER*";
ls '"$USER*"' => no expand
	res: ls: cannot access '"$USER*"': No such file or directory
```

# pseudo code 


### process_single_arg
- will handle dollar expansion, quote removal, and wildcard expansion
```ver1
process_single_arg(t_mshell *data, char *arg, t_list **new_list)
	if (arg has single quote)
		- copy except single quote and save to new_list
	else if (arg has double quote)
		- copy except double quote
		- expand dollar
		- no wc handling
		- save to new_list
	else (no quote)
		- expand dollar
		- wc handling
		- save to new_list
```

```ver2
process_single_arg(t_mshell *data, char *arg, t_list **new_list)
	int is_quoted_arg = is_quoted(arg);
	char *dllr_expanded;
	char **wc_expanded;

	if (dllr_expansion_needed(arg))
		dllr_expanded = expand_and_remove_quote(arg);
	if (!dllr_expanded)		ft_lstadd_back(new_list, expanded);
	else
		wc_expanded = wc_expand(arg);
		if (!wc_expanded)
			if (ft_lstadd_back(new_list, dllr_expanded))
				return 1
		else
			while (wc_expanded[i])
				if (ft_lstadd_back(new_list, wc_expanded[i]))
					free_strarr(wc_expanded), free(dllr_expanded), return 1;
				i++;
			free_strarr(wc_expanded);
	free(dllr_expanded);
	return 0;

```new_list, dllr_expanded))
				return 1
		else
			while (wc_expanded[i])
				if (ft_lstadd_back(new_list, wc_expanded[i]))
					free_strarr(wc_expanded), free(dllr_expanded), return 1;
				i++;
			free_strarr(wc_expanded);
	free(dllr_expanded);
	return 0;

```



```ver3
process_single_arg(t_mshell *data, char *arg, t_list **new_list)
	char *processed_arg;

	//step1: dllr, qot
	processed_arg = expand_vars_remove_quotes(data, arg);
	if (!processed_arg)
		return 1
	
	//step2: wc
	wc_res = NULL;
	if (processed_arg has '*')
		wc_res = wc_expand(processed_arg);

	//step3: add results to the list
	if (wc_res)
		while (wc_res[i])
			if (ft_lstadd_back(new_list, wc_res[i]))
				free_strarr(wc_res), free(processed_arg), return 1;
			i++;
		free_strarr(wc_res);
	else
		if (ft_lstadd_back(new_list, processed_arg))
			free(processed_arg), return 1;
	free(processed_arg);
	return 0;
```


```ver4: last
function process_single_arg(data, original_arg, new_list):
	has_unquoted_wildcard = has_unquoted_wc(original_arg)

	processed_arg = expand_vars_remove_quotes(data, original_arg)
	if processed_arg is NULL:
		return ERR

	wc_results = NULL
	if has_unquoted_wildcard and string_contains(processed_arg, '*'):
		wc_results = wc_expand(data, processed_arg)

	if wc_results is NOT NULL:
		free(processed_arg)
		processed_arg = NULL
		i = 0
		while wc_results[i] is NOT NULL:
			if ft_lstadd_back_transfer_ownership(new_list, wc_results[i]) is ERR:
				free_str_array_from(wc_results, i)
				free(wc_results)
				return ERR
			wc_results[i] = NULL
			i = i + 1
		end while
		free(wc_results)
	else:
		if ft_lstadd_back_transfer_ownership(new_list, processed_arg) is ERR:
			free(processed_arg)
			return ERR
		processed_arg = NULL

	return OK


function has_unquoted_wc(arg):
	state = UNQUOTED
	for each character c in arg:
		if c is '*' and state is UNQUOTED:
			return TRUE
		else if c is '\'' and state is UNQUOTED:
			state = SINGLE_QUOTED
		else if c is '\'' and state is SINGLE_QUOTED:
			state = UNQUOTED
		else if c is '"' and state is UNQUOTED:
			state = DOUBLE_QUOTED
		else if c is '"' and state is DOUBLE_QUOTED:
			state = UNQUOTED
	return FALSE

```





```