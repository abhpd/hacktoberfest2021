"""
This code has been designed by - Amrit Raj
The code uses the boto3 to read the contents of a .txt file stored in a S3 bucket in AWS
and transfer the contents to a DynamoDB table at AWS.
This code is for example purpose and can be suitably modified for any .txt or other file format
and for any table.
For this example, we have assumed an employee table with three attributes - id, name, and salary
"""
import boto3
client = boto3.client("s3")

dynamodb = boto3.resource('dynamodb')
table = dynamodb.Table('employee')


def lambda_handler(event, context):
    bucket_name = event['Records'][0]['s3']['bucket']['name']
    file_name = event['Records'][0]['s3']['object']['key']
    repo = client.get_object(Bucket = bucket_name, Key = file_name)
    data = repo['Body'].read().decode("utf-8")
    employees = data.split("\n")
    for emp in employees:
        print(emp)
        emp_data = emp.split(", ")

        table.put_item(
            Item = {
                "id" : int(emp_data[0]),
                "name" : emp_data[1],
                "salary" : emp_data[2]
            }
            )
