import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:http/http.dart' as http;
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_analytics/firebase_analytics.dart';
import 'dart:ui';

class MyHome extends StatefulWidget {
  @override
  _MyHomeState createState() => _MyHomeState();
}

class _MyHomeState extends State<MyHome> {
  String com;
  var a;
  String d = "";
  final firestoreInstance = FirebaseFirestore.instance;
  final FirebaseAnalytics analytics = FirebaseAnalytics();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Linux App'),
        automaticallyImplyLeading: false,
        backgroundColor: Colors.black,
        leading: IconButton(
          icon: Image.asset('image/logo.png'),
          onPressed: () {},
          padding: EdgeInsets.all(8),
        ),
      ),
      body: Container(
        height: double.infinity,
        width: double.infinity,
        color: Colors.grey.shade300,
        child: ListView(
          children: <Widget>[
            Container(
              padding: EdgeInsets.all(20),
              child: Column(
                children: <Widget>[
                  TextField(
                    onChanged: (value) {
                      com = value;
                    },
                    autocorrect: false,
                    textAlign: TextAlign.center,
                    decoration: InputDecoration(
                      border: OutlineInputBorder(),
                      hintText: "Enter the Command",
                      prefixIcon: Icon(Icons.tablet_android),
                    ),
                  ),
                  Divider(height: 20),
                  FlatButton(
                      onPressed: () async {
                        webrun();
                        onLogin();
                        // print(cmd);
                      },
                      color: Colors.black,
                      child: Text(
                        'Click Here',
                        style: TextStyle(color: Colors.white),
                      )),
                  Divider(height: 20),
                  Container(
                    width: double.infinity,
                    padding: EdgeInsets.all(10),
                    color: Colors.white,
                    child: Card(
                      color: Colors.grey.shade100,
                      borderOnForeground: true,
                      shadowColor: Colors.grey.shade500,
                      child: Column(
                        children: [
                          Text("Output",
                              style: TextStyle(
                                  fontWeight: FontWeight.bold, fontSize: 25)),
                          Divider(height: 10),
                          Center(
                            child: Text(
                              "$d",
                              style: TextStyle(
                                  //fontWeight: FontWeight.bold,
                                  fontSize: 20),
                              overflow: TextOverflow.ellipsis,
                              textAlign: TextAlign.center,
                            ),
                          )
                        ],
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }

  webrun() async {
    var url = "http://192.168.0.106/cgi-bin/web.py?w=$com";
    var response = await http.get(url);

    print(response.body);
    firestoreInstance.collection("users").add({
      com: response.body,
    }).then((value) {
      print(value.id);
      webdisplay(value.id);
    });
    return;
  }

  webdisplay(e) {
    firestoreInstance.collection("users").doc(e).get().then((value) {
      print(value.data);
      var t = value.data();
      setState(() {
        d = "${t[com]}";
      });
      print("$d");
    });
    return;
  }

  onLogin() {
    analytics.logLogin();
  }
}
