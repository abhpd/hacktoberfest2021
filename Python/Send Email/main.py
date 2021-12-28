import smtplib 
from email.message import EmailMessage

email = EmailMessage()
email['from'] = '<Your email>'
email['to'] = '<Reciver\'s Email>'
email['subject'] = 'Test Python Scipt Email'
email.set_content("Hi there, this is test email content.")

with smtlib.SMTP(host='smtp.gmail.com',port=587) as smtp:    
    smtp.ehlo()

smtp.starttls()
smtop.login("<your email>","<Password>")

smtp.send_message(email)
