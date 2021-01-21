from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage
import pyautogui
import smtplib

screen = pyautogui.screenshot()
screen.save('screen.jpg')

credenfile = open("credentials.txt", 'r')
credentials = credenfile.readlines()
credenfile.close()

msg = MIMEMultipart()
msg['From'] = credentials[0]
password = credentials[1]
msg['To'] = credentials[2]
msg['subject'] = "screen"
fichier = open('screen.jpg', 'rb')
image = MIMEImage(fichier.read())
fichier.close()
msg.attach(image)

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(msg['From'], password)
server.sendmail(msg['From'], msg['To'], msg.as_string())
server.quit()


