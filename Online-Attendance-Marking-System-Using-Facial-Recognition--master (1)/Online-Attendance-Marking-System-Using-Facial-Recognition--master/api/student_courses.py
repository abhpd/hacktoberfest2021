from flask_jwt import jwt_required, current_identity
from flask_restful import Resource

from db.db_util import get_student, get_student_courses, get_course


class StudentCourses(Resource):
    @jwt_required()
    def get(self, user_id):
        if user_id == current_identity.id and current_identity.is_student:
            student_courses = get_student_courses(user_id)
            if student_courses:
                courses_list = []
                for course in student_courses:
                    courses_list.append(get_course(course))
                return courses_list
            return {'message': 'Student\'s courses not found'}, 200
        else:
            return {'message': 'You are not authorized to view this student\'s courses'}, 404
