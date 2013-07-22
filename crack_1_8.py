'''
according http://hawstein.com/posts/1.8.html
algorithm is that str1= "12345",str2= "51234"
str1 = str1 + str1 = "1234512345"
as a result, str2 is subString of str1
'''
str1 = 'abcdefghi'
str2 = 'ihgfedcba'

def isSubString(str1, str2):
	if str2 in str1:
		return True
	return False

def isRotation(str1, str2):
	if isSubString(str1+str2, str2):
		return True
	return False

print isRotation(str1, str2)