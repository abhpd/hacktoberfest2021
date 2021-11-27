from datetime import datetime, timedelta

from db.db_util import get_connection


def setup():
    create_tables()
    insert_users()
    insert_students()
    insert_faculties()
    insert_courses()
    insert_student_courses()
    # insert_classes()
    # insert_attendance()


def create_tables():
    connection = get_connection()
    cursor = connection.cursor()

    create_table = 'CREATE TABLE IF NOT EXISTS user (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL UNIQUE, password TEXT NOT NULL, is_student BOOLEAN DEFAULT FALSE)'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY, student_id TEXT NOT NULL UNIQUE, student_name TEXT NOT NULL, FOREIGN KEY (id) REFERENCES user (id))'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS faculty (id INTEGER PRIMARY KEY, faculty_id TEXT NOT NULL UNIQUE, faculty_name TEXT NOT NULL, FOREIGN KEY (id) REFERENCES user (id))'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS course (id INTEGER PRIMARY KEY AUTOINCREMENT, course_code TEXT NOT NULL UNIQUE, course_name TEXT NOT NULL, faculty_id INTEGER NOT NULL, FOREIGN KEY (faculty_id) REFERENCES faculty (id))'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS student_course (student_id INTEGER NOT NULL, course_id INTEGER NOT NULL, PRIMARY KEY (student_id, course_id), FOREIGN KEY (student_id) REFERENCES student (id), FOREIGN KEY (course_id) REFERENCES course (id))'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS class (id INTEGER PRIMARY KEY AUTOINCREMENT, course_id INTEGER, start_time TIMESTAMP NOT NULL, end_time TIMESTAMP, FOREIGN KEY (course_id) REFERENCES course (id))'
    cursor.execute(create_table)

    create_table = 'CREATE TABLE IF NOT EXISTS attendance (id INTEGER PRIMARY KEY AUTOINCREMENT, class_id INTEGER, student_id INTEGER, is_present BOOLEAN DEFAULT TRUE, UNIQUE (class_id, student_id, is_present) FOREIGN KEY (class_id) REFERENCES class (id), FOREIGN KEY (student_id) REFERENCES student (id))'
    cursor.execute(create_table)

    connection.close()


def insert_users():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO user (username, password, is_student) VALUES (?, ?, ?)"

    users = [
        ('nimisha', 'asdf', True),
        ('tanay', 'asdf', True),
        ('daksh', 'xyz', True),
        ('sumit', 'xyz', True),
        ('kavya', 'xyz', True),
        ('anisha', 'xyz', True),
        ('himanshu', 'xyz', True),
        ('ankita', 'xyz', True),
        ('stuti', 'xyz', True),
        ('parth', 'xyz', True),
        ('amit', 'xyz', False),
        ('kunal', 'xyz', False),
        ('pooja', 'xyz', False),
        ('manas', 'xyz', False),
        ('priya', 'xyz', False)
    ]
    cursor.executemany(insert_query, users)

    connection.close()


def insert_students():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO student (id, student_id, student_name) VALUES (?, ?, ?)"
    students = [
        (1, '19BCE1860', 'Nimisha Swain'),
        (2, '19BCE1563', 'Tanay Vaishnav'),
        (3, '19BCE1320', 'Daksh Sethi'),
        (4, '19BCE1600', 'Sumit Swain'),
        (5, '19BCE1426', 'Kavya Kapoor'),
        (6, '19BCE1123', 'Anisha Kaushik'),
        (7, '19BCE1024', 'Himanshu Barik'),
        (8, '19BCE1480', 'Ankita Bagaliker'),
        (9, '19BCE1725', 'Stuti Singh'),
        (10, '19BCE1670', 'Parth Singh')

    ]

    cursor.executemany(insert_query, students)

    connection.close()


def insert_faculties():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO faculty (id, faculty_id, faculty_name) VALUES (?, ?, ?)"
    faculties = [
        (11, '11FAC1078', 'Amit Tyagi'),
        (12, '12FAC1346', 'Kunal Kapoor'),
        (13, '12FAC1005', 'Pooja Johar'),
        (14, '16FAC1089', 'Manas Murli'),
        (15, '18FAC1234', 'Priya Bhatt')

    ]

    cursor.executemany(insert_query, faculties)

    connection.close()


def insert_courses():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO course (course_code, course_name, faculty_id) VALUES (?, ?, ?)"
    courses = [
        ('CSE2002', 'Data Structure And Algorithm', 12),
        ('CSE2004', 'Network And Communication', 12),
        ('CHE2003', 'Engineering Chemistry', 15),
        ('CSE3001', 'Software Engineering', 15),
        ('CSE3002', 'Internet And Web Programming', 12),
        ('PHY1002', 'Engineering Physics', 13),
        ('STS1106', 'Soft Skills', 15),
        ('PHY1105', 'Introduction to Innovative Projects', 13),
        ('CSE5002', 'Introduction to Machine Learning', 13)
    ]

    cursor.executemany(insert_query, courses)

    connection.close()


def insert_student_courses():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO student_course (student_id, course_id) VALUES (?, ?)"
    student_courses = [
        (1, 1),
        (1, 2),
        (1, 3),
        (1, 5),
        (1, 6),
        (2, 1),
        (2, 5),
        (2, 3),
        (2, 8),
        (2, 9),
        (3, 1),
        (3, 5),
        (3, 6),
        (3, 3),
        (4, 6),
        (4, 1),
        (4, 5),
        (5, 1),
        (5, 5),
        (6, 1),
        (6, 5),
        (7, 1),
        (7, 5),
        (8, 1),
        (8, 5),
        (9, 5),
        (10, 5)
    ]

    cursor.executemany(insert_query, student_courses)

    connection.close()


def insert_classes():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO class (course_id, start_time, end_time) VALUES (?, ?, ?)"
    classes = [
        (1, datetime.now() - timedelta(days=1), datetime.now()),
    ]

    cursor.executemany(insert_query, classes)

    connection.close()


def insert_attendance():
    connection = get_connection()
    cursor = connection.cursor()

    insert_query = "INSERT INTO attendance (student_id, class_id) VALUES (?, ?)"
    attendance = [
        (1, 1),
        (1, 2),
    ]

    cursor.executemany(insert_query, attendance)

    connection.close()


if __name__ == "__main__":
    setup()
