from flask import Flask, request
from flask_restful import Resource, Api
from flask_cors import CORS
from py2neo import Graph

app = Flask(__name__)
api = Api(app)
CORS(app)
url = "db_HOST"
graph = Graph(url, user="db_USERNAME",
              password="db_PASSWORD", name="db_NAME")


class run(Resource):
    def post(self):
        run = request.form["run"]
        response = graph.run(run).data()
        return response


api.add_resource(run, "/run", methods=["POST"])

if __name__ == "__main__":
    app.run(debug=True, port=5000)
