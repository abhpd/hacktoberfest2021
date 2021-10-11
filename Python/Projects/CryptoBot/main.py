import schedule
import time
import cryptocompare
import os
from twilio.rest import Client
from dotenv import load_dotenv
load_dotenv()

def main():
    account_sid = os.getenv('account_sid')
    auth_token = os.getenv('auth_token')
    client = Client(account_sid, auth_token)
    sender_phone = os.getenv('sender_phone')
    target_phone = os.getenv('target_phone')

    cryptos = ['BTC', 'NCASH', 'REQ', 'XRP']
    crypto_prices = {}

    for crypto in cryptos:
        crypto_price = cryptocompare.get_price(crypto, curr='INR')[crypto]['INR']
        crypto_prices[crypto] = crypto_price

    body_message_arr = ["Today's Prices", "===============>"]
    for crypto in crypto_prices:
        body_message_arr.append(crypto + ': ₹{}'.format(crypto_prices[crypto]))

    body_message = '\n'.join(body_message_arr)

    sent_message = client.messages.create(
        to=target_phone,
        from_=sender_phone,
        body=body_message
    )

schedule.every().day.at("20:00").do(main)

while True:
    schedule.run_pending()
    time.sleep(60)
