let user;

$(document).ready(function () {
    checkLoggedIn()
    $("#content").fadeIn();

    $.get({
        url: "/api/user",
        headers: {
            Authorization: 'JWT ' + Cookies.get('access_token')
        },
        success: function (data) {
            user = data;
            user = getUserData(user);
            getCourseData(user);
        },
        error: function (e) {
            Cookies.remove('access_token')
            checkLoggedIn()
        }
    });
})

function getCourseData(user) {
    if (user.is_student) {
        $.get({
            url: "/api/student/" + user.id + "/courses",
            headers: {
                Authorization: 'JWT ' + Cookies.get('access_token')
            },
            success: function (data) {
                addCourses(data)
            },
            error: function (e) {
                console.log("ERROR : ", e);
            }
        });
    } else {
        $.get({
            url: "/api/faculty/" + user.id + "/courses",
            headers: {
                Authorization: 'JWT ' + Cookies.get('access_token')
            },
            success: function (data) {
                addCourses(data)
            },
            error: function (e) {
                console.log("ERROR : ", e);
            }
        });
    }
}

function addCourses(courses) {
    let courseList = $('#course-list');
    let dummyCourse = $('#dummy-course');
    for (let course of courses) {
        let clone = dummyCourse.clone();
        clone.attr("id", course.course_code);
        courseList.append(clone);

        $("#" + course.course_code + " #course-name").text(course.course_name);
        $("#" + course.course_code + " #view-course").attr("href", "/course/" + course.course_code);
    }
    dummyCourse.remove();
}