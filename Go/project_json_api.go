package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
)

type NilaiMahasiswa struct {
	ID          uint   `json:"id"`
	Nama        string `json:"nama"`
	MataKuliah  string `json:"matakuliah"`
	Nilai       uint   `json:"nilai"`
	IndeksNilai string `json:"indeksnilai"`
}

var nilaiNilaiMahasiswa = []NilaiMahasiswa{}

func getIndeksNilai(nilai uint) string {

	switch {
	case nilai >= 80:
		return "A"
	case nilai >= 70 && nilai < 80:
		return "B"
	case nilai >= 60 && nilai < 70:
		return "C"
	case nilai >= 50 && nilai < 60:
		return "D"
	default:
		return "E"
	}
}

func GetMahasiswa(rw http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {

		data, err := json.Marshal(nilaiNilaiMahasiswa)
		if err != nil {
			fmt.Println(err.Error())
			return
		}

		rw.Header().Set("Content-Type", "application/json")
		rw.WriteHeader(http.StatusOK)
		rw.Write(data)
		return
	}
	http.Error(rw, "access not allow !", http.StatusMethodNotAllowed)
}

func PostMahasiswa(rw http.ResponseWriter, r *http.Request) {
	rw.Header().Set("Content-Type", "application/json")

	if r.Method == "POST" {

		var nilaiMhs = NilaiMahasiswa{
			ID: uint(len(nilaiNilaiMahasiswa) + 1),
		}
		if r.Header.Get("Content-Type") == "application/json" {
			decodejson := json.NewDecoder(r.Body)

			if err := decodejson.Decode(&nilaiMhs); err != nil {
				log.Fatal(err)
			}
		} else {
			nama := r.FormValue("nama")
			makul := r.FormValue("matakuliah")
			getnilai := r.FormValue("nilai")
			nilai, _ := strconv.Atoi(getnilai)

			nilaiMhs.Nama = nama
			nilaiMhs.MataKuliah = makul
			nilaiMhs.Nilai = uint(nilai)
		}

		if nilaiMhs.Nilai > 100 {
			http.Error(rw, "nilai tidak boleh diinput lebih  dari 100", http.StatusBadRequest)
			return
		}

		nilaiMhs.IndeksNilai = getIndeksNilai(nilaiMhs.Nilai)

		dataNilai, _ := json.Marshal(nilaiMhs)
		nilaiNilaiMahasiswa = append(nilaiNilaiMahasiswa, nilaiMhs)
		rw.Write(dataNilai)
		return

	}
	http.Error(rw, "access not allow !", http.StatusMethodNotAllowed)
}

func Auth(next http.Handler) http.Handler {
	return http.HandlerFunc(func(rw http.ResponseWriter, r *http.Request) {
		username, password, oke := r.BasicAuth()

		if !oke {
			rw.Write([]byte("harus mengisi username dan password"))
			return
		}

		if username == "joko" && password == "123" {
			next.ServeHTTP(rw, r)
			return
		}

		rw.Write([]byte("uasername dan password yang anda masukan salah, ulangi lagi"))
		return
	})
}

func main() {
	http.HandleFunc("/mahasiswa", GetMahasiswa)
	http.Handle("/buat-mahasiswa", Auth(http.HandlerFunc(PostMahasiswa)))

	fmt.Println("Server berjalan di port 5000")

	log.Fatal(http.ListenAndServe(":5000", nil))
}
