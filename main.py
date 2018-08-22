import re
file = open("example-requirements.json", "r") 
req = file.read()
p = re.compile('\{|\}|Dependencies = |,')
# print(p.sub('',req))
f=open("requirements.txt", "w")

subbed_req = p.sub('',req)

p = re.compile('\n\n')
f.write(p.sub('',subbed_req))
f.close()

with open("requirements.txt") as file:
    content = file.readlines()
content = [x.strip() for x in content] 

print(content)

import subprocess

for x in content:
	try:
		cmd = 'pip install '+x
		returned_value = subprocess.call(cmd, shell=True, stdout=subprocess.PIPE)
		# print(returned_value)
		returned_value = subprocess.Popen("pip freeze | grep "+x, shell=True, stdout=subprocess.PIPE)
		# print("######################################")
		output = returned_value.communicate()[0]
		# print(output,x,str(output).find(x))	
		# print("######################################")
		if str(output).find(x)!=-1:
			print("###### Installation Successful for "+ x)
		else:
			print("###### Installation Failed for "+ x)
	except:
		pass
