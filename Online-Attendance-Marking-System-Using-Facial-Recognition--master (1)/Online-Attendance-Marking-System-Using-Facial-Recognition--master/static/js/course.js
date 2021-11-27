let user;
let course;

$(document).ready(function () {
    checkLoggedIn()

    $('#webcam-container').hide();
    $('#webcam-result').hide();
    $("#content").fadeIn();

    $.get({
        url: "/api/user",
        headers: {
            Authorization: 'JWT ' + Cookies.get('access_token')
        },
        success: function (data) {
            user = data;
            user = getUserData(user);
            getCourseData();
            getAttendanceData();
        },
        error: function (e) {
            Cookies.remove('access_token')
            console.log("ERROR : ", e);
        }
    });
})

function getAttendanceData() {
    $.get({
        url: "/api/attendance/" + course_id,
        headers: {
            Authorization: 'JWT ' + Cookies.get('access_token')
        },
        data: {user_id: user.id},
        success: function (data) {
            showAttendanceDetails(data);
        },
        error: function (e) {
            console.log("ERROR : ", e);
        }
    });
}

function getCourseData() {
    $.get({
        url: "/api/course/" + course_id,
        headers: {
            Authorization: 'JWT ' + Cookies.get('access_token')
        },
        success: function (data) {
            course = data;
            updateCourseButton()
        },
        error: function (e) {
            console.log("ERROR : ", e);
        }
    });
}

function changeCourseState() {
    $.post({
        url: "/api/attendance/" + course_id,
        data: {user_id: user.id},
        headers: {
            Authorization: 'JWT ' + Cookies.get('access_token')
        },
        success: function (data) {
            alert(data.message);
            course.is_ongoing = !course.is_ongoing
            updateCourseButton()
        },
        error: function (e) {
            console.log("ERROR : ", e);
        }
    });
}

function updateCourseButton() {
    let courseBtn = $("#course-btn");
    if (user.is_student) {
        courseBtn.attr("disabled", !course.is_ongoing)
        courseBtn.click(attendClass)
        if (course.is_ongoing) {
            courseBtn.html("Attend ongoing class");
            courseBtn.addClass("btn-outline-success")
        } else {
            courseBtn.html("No ongoing class");
            courseBtn.addClass("btn-outline-danger")
        }
    } else {
        courseBtn.click(changeCourseState);
        if (course.is_ongoing) {
            courseBtn.html("Stop ongoing class");
            courseBtn.addClass("btn-outline-danger")
        } else {
            courseBtn.html("Start a new class");
            courseBtn.addClass("btn-outline-success")
        }
    }
}

function showAttendanceDetails(data) {
    let thead, tbody, trow;
    const attendanceInfo = $("#attendance-info")
    const attendanceTable = $("#attendance-table")
    attendanceInfo.empty()
    attendanceTable.empty()

    if (user.is_student) {
        let presentClasses = data.filter(x => x.is_present).length

        $("<h3>").html("Attendance Info").appendTo(attendanceInfo)
        $("<h4>", {"class": "card-subtitle text-muted"}).html(
            "Present classes: " + presentClasses + "<br>" +
            "Absent classes: " + (data.length - presentClasses) + "<br>" +
            "Total classes : " + data.length + "<br>" +
            "Attendance percentage : " + (presentClasses * 100 / data.length).toFixed(2) + "%"
        ).appendTo(attendanceInfo)

        thead = $("<thead>").appendTo(attendanceTable);
        trow = $("<tr>").appendTo(thead);
        // For loop for adding header .i.e th to our table
        jQuery.each(["#", "Start time", "End time", "Marked as"], function (index, header) {
            $("<th>", {"scope": "col"}).appendTo(trow).html(header);
        });

        //For loop for adding data .i.e td with data to our dynamic generated table
        tbody = $("<tbody>").appendTo(attendanceTable);
        jQuery.each(data, function (index, value) {
            trow = $("<tr>").appendTo(tbody);
            if (value.is_present) {
                trow.addClass("table-success")
            } else {
                trow.addClass("table-danger")
            }
            $("<th>", {"scope": "row"}).appendTo(trow).html(index + 1);
            $("<td>").appendTo(trow).html(value.start_time);                // TODO better datetime formatting
            $("<td>").appendTo(trow).html(value.end_time || "Ongoing");     // TODO better datetime formatting
            $("<td>").appendTo(trow).html(value.is_present ? "Present" : "Absent");
        });
    } else {
        let passingStudentsCount = data.filter(x => x.attendance_percent >= 75.0).length

        $("<h3>").html("Attendance Info").appendTo(attendanceInfo)
        $("<h4>", {"class": "card-subtitle text-muted"}).html(
            "Students with >=75% attendance : " + passingStudentsCount + "<br>" +
            "Students with <75% attendance : " + (data.length - passingStudentsCount) + "<br>" +
            "Total students : " + data.length
        ).appendTo(attendanceInfo)

        thead = $("<thead>").appendTo(attendanceTable);
        trow = $("<tr>").appendTo(thead);
        // For loop for adding header .i.e th to our table
        jQuery.each(["#", "Student ID", "Student Name", "Present", "Absent", "Total", "Attendance %"], function (index, header) {
            $("<th>", {"scope": "col"}).appendTo(trow).html(header);
        });

        //For loop for adding data .i.e td with data to our dynamic generated table
        tbody = $("<tbody>").appendTo(attendanceTable);
        jQuery.each(data, function (index, value) {
            trow = $("<tr>").appendTo(tbody);
            if (value.attendance_percent < 75) {
                trow.addClass("table-danger")
            } else if (value.attendance_percent > 90) {
                trow.addClass("table-success")
            }
            $("<th>", {"scope": "row"}).appendTo(trow).html(index + 1);
            $("<td>").appendTo(trow).html(value.student_id);
            $("<td>").appendTo(trow).html(value.student_name);
            $("<td>").appendTo(trow).html(value.present_count);
            $("<td>").appendTo(trow).html(value.total_count - value.present_count);
            $("<td>").appendTo(trow).html(value.total_count);
            $("<td>").appendTo(trow).html(value.attendance_percent + "%");
        });
    }
}

function attendClass() {
    $('#webcam-container').show();
}