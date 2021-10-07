def checkBalancedParantheses(s):
  '''
  Checks if a string contains balanced parantheses. Takes a string as an input
  '''
	stack = []
	for i in range(len(s)):
		if s[i] == '[' or s[i] == '{' or s[i] == '(':
			stack.append(s[i])
		else:
			if not stack:
				return False
			q = stack.pop()
			if s[i] == '[' and q != ']':
				return False
			elif s[i] == ' (' and q != ')':
				return False
			elif s[i] == '{' and q != '}':
				return False
	if stack:
		return False
	else:
		return True

s = "[{}{}(]"         # returns False
print(checkBalancedParantheses(s))

s1 = "{([{[]}])}"     # returns True
print(checkBalancedParantheses(s1))
