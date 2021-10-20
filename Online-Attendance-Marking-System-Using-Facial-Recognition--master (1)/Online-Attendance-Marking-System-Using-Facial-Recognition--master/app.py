import os
from datetime import timedelta

from flask import Flask, render_template, send_from_directory
from flask_jwt import JWT
from flask_restful import Api

from api.attendance import Attendance
from api.course import CourseApi
from api.faculty import Faculty
from api.faculty_courses import FacultyCourses
from api.student import Student
from api.student_courses import StudentCourses
from api.user import UserRegister, UserApi
from db.db_util import get_course_id
from security import authenticate, identity

app = Flask(__name__)
app.secret_key = '3d6f45a5fc12445dbac2f59c3b6c7cb1'
app.config['JWT_EXPIRATION_DELTA'] = timedelta(seconds=30000)
api = Api(app)

jwt = JWT(app, authenticate, identity)  # /auth


@app.route('/login')
def login():
    return render_template('login.html')


@app.route('/course/<string:course_code>')
def course(course_code):
    course_id = get_course_id(course_code)
    return render_template('course.html', course_id=course_id)


@app.route('/')
@app.route('/home')
def home():
    return render_template('home.html')


@app.route('/favicon.ico')
def favicon():
    return send_from_directory(os.path.join(app.root_path, 'static', 'img'),
                               'favicon.ico', mimetype='image/vnd.microsoft.icon')


api.add_resource(UserApi, '/api/user/')
api.add_resource(UserRegister, '/api/register')
api.add_resource(Student, '/api/student/<int:user_id>')
api.add_resource(StudentCourses, '/api/student/<int:user_id>/courses')
api.add_resource(Faculty, '/api/faculty/<int:user_id>')
api.add_resource(FacultyCourses, '/api/faculty/<int:user_id>/courses')
api.add_resource(CourseApi, '/api/course/<int:course_id>')
api.add_resource(Attendance, '/api/attendance/<int:course_id>')

if __name__ == '__main__':
    app.run(port=5000, debug=True)
