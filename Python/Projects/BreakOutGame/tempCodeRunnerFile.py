import pygame
import sys
import os
## breakout #
################### menjalankan pygame #######################
pygame.init()
################### membuat judul ############################
pygame.display.set_caption("TUBES")

####################### luas UI ##############################
LEBAR = 600
TINGGI = 600

###################### WARNA WARNI ############################
HITAM = (0, 0, 0)  # WARNA HITAM
PUTIH = (255, 255, 255)  # WARNA PUTIH
HIJAU = (144, 190, 109)  # WARNA HIJAU
MERAH = (249, 65, 68)  # WARNA MERAH
BIRU = (87, 117, 144)  #WARNA BIRU
NETRAL = (52, 58, 64)  # WARNA ATAU NETRAL
ABU = (108, 117, 125) #WARNA ABU
KUNING = (249, 199, 79)  # WARNA KUNING
OREN = (243, 114, 44)  # WARNA OREAN
PINK = (252, 100, 203)  # WARNA PINK

######################## ASET ###################################
# MENAMPIKAN JUDUL PADA GAME
MUKA_KELOMPOK = pygame.image.load(os.path.join(sys.path[0],'Foto_tubes.png'))
# MEMBUAT LAGU BUAT KALO KENA TEMBOK
SUARA_KENA_TEMBOK = pygame.mixer.Sound(
    os.path.join(sys.path[0], "Suara_UwU_eliza.wav"))
#MEMBUAT LAGU BUAT KALO KENA BONUS
SUARA_KENA_BONUS = pygame.mixer.Sound(
    os.path.join(sys.path[0], "Breakout_bounce.wav"))


################## MENGECEK BOLA HIDUP ATAI TIDAK ###############
# VARIABLE UNTUK NGECEK BOLA MASIH HIDUP ATAU TIDAK
bola_hidup = True
selesai = 0

################## membuat tampilan pada game ###################
#MEMBUAT VARIABLE TAMPILAN SIZE GAME SAAT DI PLAY
tampilan = pygame.display.set_mode((LEBAR, TINGGI))
# MEMBUAT VARIABLE UNTUK MEMBUAT TULISAN
huruf = pygame.font.SysFont('Poppins Bold', 30)

##################### KLIK PADA MOUSE ###########################
klik = False

################## KLAS UNTUK MENU DAN GAME OVER ################
class Tombol:
    def __init__(self, x, y, tulisan, warna):

        # MENDEKLARASIKAN VARIABLE YAG DI BUTUHKAN
        self.warna_hover = (61, 64, 91)
        self.warna_klik = (129, 178, 154)
        self.warna_tulisan =(244, 241, 222)
        self.lebar = 180
        self.tinggi = 70
        self.warna_tombol = warna
        self.x = x
        self.y = y
        self.tulisan = tulisan

    #UNGSI UNTUK MENAMPILKAN TOMBOL
    def menampilkan_tombol(self):

        global klik
        aksi = False

        # MEMBUAT VARIABEL UNTUK MOUSE
        pos = pygame.mouse.get_pos()

        #MEMBUAT PENEMPADATAN UNTUK TOMBOL
        tombol_rect = pygame.Rect(self.x, self.y, self.lebar, self.tinggi)

        #MEMERIKSA APAKAH SUDAH DI KLIK ATAU BELOM
        if tombol_rect.collidepoint(pos):
            if pygame.mouse.get_pressed()[0] == 1:
                klik = True
                pygame.draw.rect(tampilan, self.warna_klik, tombol_rect)
            elif pygame.mouse.get_pressed()[0] == 0 and klik == True:
                klik = False
                aksi = True
            else:
                pygame.draw.rect(tampilan, self.warna_hover, tombol_rect)
        else:
            pygame.draw.rect(tampilan, self.warna_tombol, tombol_rect)

        # MEMBUAT TULISAN PADA TOMBOL
        gambar_tulisan = huruf.render(self.tulisan, True, self.warna_tulisan)
        panjang_tulisan = gambar_tulisan.get_width()
        tampilan.blit(gambar_tulisan,
                      (self.x + int(self.lebar / 2) - int(panjang_tulisan / 2),
                       self.y + 25))
        return aksi


################## KLAS UNTUK MEMBUAT TEMBOK ###################
class Tembok():
    def __init__(self):
        ####################### JUAMLAH TEMBOK ##########################
            # JUMLAH BARIS DAN KOLOM
        self.baris_inti = 6
        self.kolom_inti = 6  
        # MEMBUAT DEKLARASI PANJANG DAN LEBAR beton
        self.lebar = LEBAR // self.baris_inti
        self.tinggi = 50

    # MEMBUAT TEMBOK
    def membuat_tembok(self,satu=1):
        self.kotak = []
        kotak_satuan = []

        for baris in range(self.kolom_inti):
            baris_kotak = []
            for kolom in range(self.baris_inti):
                kotak_x = kolom * self.lebar
                kotak_y = baris * self.tinggi
                rect = pygame.Rect(kotak_x, kotak_y, self.lebar, self.tinggi)

                # JIKA ADA DI BARIS KE 1 2 3 MAKA KEKUATAN BETON NYA 2
                if baris < 3:
                    kekuatan = 2
                # JIKA ADA DI BARIS KE 3 4 5 MAKA KEKUATAN BETON NYA 1
                elif baris < 5:
                    kekuatan = satu
                # MENGINPUTKAN BETON
                kotak_satuan = [rect, kekuatan]
                baris_kotak.append(kotak_satuan)

            self.kotak.append(baris_kotak)

    # MENAMPILKAN BETON KE GAME
    def tampil_beton(self):
        for baris in self.kotak:
            for kotak in baris:
                # KALO KEKUATAN NYA 2 WARNA BETON NYA ABU ABU
                if kotak[1] == 2:
                    warna = ABU
                # KALO KEKUATAN NYA 1 WARNA BETON NYA OREN
                elif kotak[1] == 1:
                    warna = OREN
                pygame.draw.rect(tampilan, warna, kotak[0])
                pygame.draw.rect(tampilan, PUTIH, kotak[0], 2)


######################## KELAS UNTUK MEMBUAT GAYUNG ##################
class Tangan:
    def __init__(self, warna):
        self.tangan_awal(warna)

    
    def tangan_awal(self,warna):
        # MENDEKLARASIKAN VARIABLE YANG DI BUTUHKAN DAYUNG
        self.tinggi = 25
        self.lebar = int(LEBAR / 4)
        self.x = int((LEBAR / 2) - (self.lebar / 2))
        self.y = TINGGI - (self.tinggi * 2)
        self.kecepatan = 2
        self.rect = pygame.Rect(self.x, self.y, self.lebar, self.tinggi)
        self.arah = 0
        self.warna = warna

    # FUNGSI UNTUK MENGGERAKAN DAYUNG
    def gerak(self):

        tombol = pygame.key.get_pressed()
        # KALO MENCET KIRI VEKTOR GAYUNG NYA DI KURANG 1
        if tombol[pygame.K_LEFT] and self.rect.left > 0:
            self.rect.x -= self.kecepatan
            self.arah = -1

        # KALO MENCET KANAN VEKTOR GAYUNG NYA DI TAMBAH 1
        if tombol[pygame.K_RIGHT] and self.rect.right < LEBAR:
            self.rect.x += self.kecepatan
            self.arah = 1

    # FUNGSI UNTUK MENAMPILKAN GAYUNG
    def tampil(self):
        pygame.draw.rect(tampilan, self.warna, self.rect)


################ KELAS UNTUK MEMBUAT BOLA #######################
class Bola:
    def __init__(self, x, y, warna):
        self.bola_awal(x,y,warna)
    
    def bola_awal(self,x,y,warna):
        # MENDEKLARASIKAN VARIABLE YANG DI PAKAI OLEH BOLA
        self.bola = 10
        self.x = x - self.bola
        self.y = y
        self.rect = pygame.Rect(self.x, self.y, self.bola * 2, self.bola * 2)
        self.kecepatan_x = 1
        self.kecepatan_y = -1
        self.selesai = 0
        self.kecepatan_max = 1
        self.warna = warna
        self.skor = 0
        self.bonus_score = False
        self.hitung = 0
        self.cek_tembok_20 = False
        self.cek_bola_nyentuh = False

    #FUNGSI UNTUK MENAMPILKAN BOLA
    def tampil(self):
        pygame.draw.circle(tampilan, self.warna,
                           (self.rect.x + self.bola, self.rect.y + self.bola),
                           self.bola)

    # FUNGSI UNTUK MENGECEK PERGERAKAN BOLA
    def gerak(self):

        hancur_tembok = 1
        penggaris = 0
        for baris in tembok.kotak:
            perhitung = 0
            for benda in baris:
                # MEMBUAT ARAH GERAK BOLA
                if self.rect.colliderect(benda[0]):
                    if abs(self.rect.bottom -
                           benda[0].top) < 5 and self.kecepatan_y > 0:
                        self.kecepatan_y *= -1
                    if abs(self.rect.top -
                           benda[0].bottom) < 5 and self.kecepatan_y < 0:
                        self.kecepatan_y *= -1
                    if abs(self.rect.right -
                           benda[0].left) < 5 and self.kecepatan_x > 0:
                        self.kecepatan_x *= -1
                    if abs(self.rect.left -
                           benda[0].right) < 5 and self.kecepatan_x < 0:
                        self.kecepatan_x *= -1

                    # MENEGCEK APAKAH BETON ABU ABU HANCUR
                    if tembok.kotak[penggaris][perhitung][1] > 1:
                        tembok.kotak[penggaris][perhitung][1] -= 1
                        SUARA_KENA_TEMBOK.play()

                    #MENGECEK SAAT BETON OREN HANCUR
                    else:
                        tembok.kotak[penggaris][perhitung][0] = (0, 0, 0, 0)
                        # SAAT BETON HANCUR MAKA SKOR AKAN  BERTAMBAH 1
                        self.skor += 1
                        #SAAT BETON SUDAH HANCUR KELIPATAN 3 MAKA TRIGER BONUS AKAN AKTIF
                        self.hitung += 1
                        if self.hitung % 3 == 0:
                            self.bonus_score = True
                        # SAAT BOLA KENA MAKA AKA ADA SUARA LUCU
                        SUARA_KENA_TEMBOK.play()
                        # SAAT BETON ANCUR 20x MAKA BETON AKAN KEMBALI SEMULA DENGAN WARNA ABU-ABU DAN JUGA KECEPATAN BOLA BERTAMBAH
                        if self.hitung % 20 == 0 :
                            self.cek_tembok_20 = True
                            self.kecepatan_max += 1

                #JIKA SEMUA TEMBOK TIDAK HANCUR MAKA GAME GAK AKAN BERAKHIR
                if tembok.kotak[penggaris][perhitung][0] != (0, 0, 0, 0):
                    hancur_tembok = 0

                perhitung += 1

            penggaris += 1


        #JIKA BOLA KENA UJUNG KANAN KIRI MAKA BOLA MANTUL
        if self.rect.left < 0 or self.rect.right > LEBAR:
            self.kecepatan_x *= -1

        # JIKA BOLA KENA ATAS MAKA AKAN MANTUL
        if self.rect.top < 0:
            self.kecepatan_y *= -1
        # JIKA BOLA KENA BAWAH ATAU JATUH MAKA GAME OVER
        if self.rect.bottom > TINGGI:
            self.selesai = -1

        # JIKA BOLA KENA AMA GAYUNG
        if self.rect.colliderect(pemain):

            #SAAT BETON ANCUR 20x MAKA BOLA DI CEK NYENTUK GAYUNG ATAU TIDAK
            if self.cek_tembok_20 :
                self.cek_bola_nyentuh = True

            if abs(self.rect.bottom -
                   pemain.rect.top) < 5 and self.kecepatan_y > 0:
                self.kecepatan_y *= -1
                self.kecepatan_x += pemain.arah

                if self.kecepatan_x > self.kecepatan_max:
                    self.kecepatan_x = self.kecepatan_max
                elif self.kecepatan_x < 0 and self.kecepatan_x < -self.kecepatan_max:
                    self.kecepatan_x = -self.kecepatan_max

            else:
                self.kecepatan_x *= -1
        # BOLA VEKTOR BOLA AKAN TERUS BERTAMBAH ATAU BERKURANG SELAMA LOOPING
        self.rect.x += self.kecepatan_x
        self.rect.y += self.kecepatan_y

        # AKAN MENGEMBALIKAN VALUE SELESAI UNTUK MENGECEK GAME OVER
        return self.selesai


########################### KLAS UNTUK MEMBUAT BONUS ########################
class Bonus:
    def __init__(self, x, y, warna=PINK):
        # MEMBUAT DEKLARASI VARIABLE YANG DIBUTUHKAN UNTUK KLAS BONUS
        self.bola = 10
        self.x = x - self.bola
        self.y = y
        self.rect = pygame.Rect(self.x, self.y, self.bola * 2, self.bola * 2)
        self.kecepatan_x = 1
        self.kecepatan_y = 1
        self.warna = warna
        self.nyentuh = False

    # FUNGSI UNTUK MENAMPILKAN BONUS
    def tampil(self):
        pygame.draw.circle(tampilan, self.warna,
                           (self.rect.x + self.bola, self.rect.y + self.bola),
                           self.bola)

    #FUNGSI UNTUK MELETAKAN BONUS
    def letak(self):
        self.rect.x = 300
        self.rect.y = 0

    # FUNGSI UNTUK BERGERAK JATUH
    def gerak(self):

        # JIKA BOLE MENYENTUH BONUS MAKA TRUE
        if self.rect.colliderect(pemain):
            self.letak()
            self.nyentuh = True

        # VEKTOR BONUS AKAN SELALU KEBAWAH SELAMA LOOPING TERPENUHI
        self.rect.y += self.kecepatan_y

class Berhenti:
    def __init__(self, x, y, tulisan, ukuran):

        # MENDEKLARASIKAN VARIABLE YAG DI BUTUHKAN
        
        
        self.warna_tulisan = MERAH
        self.x = x
        self.y = y
        self.tulisan = tulisan
        self.huruf = pygame.font.SysFont('Ubuntu', ukuran)

    #UNGSI UNTUK MENAMPILKAN TOMBOL
    def menampilkan_tombol(self):

        global klik
        aksi = False

        # MEMBUAT VARIABEL UNTUK MOUSE
        pos = pygame.mouse.get_pos()

        tombol_rect = pygame.Rect(self.x, self.y, 180, 70)

        #MEMERIKSA APAKAH SUDAH DI KLIK ATAU BELOM
        if tombol_rect.collidepoint(pos):
            if pygame.mouse.get_pressed()[0] == 1:
                klik = True
            elif pygame.mouse.get_pressed()[0] == 0 and klik == True:
                klik = False
                aksi = True
        

        # MEMBUAT TULISAN PADA TOMBOL
        gambar_tulisan = self.huruf.render(self.tulisan, True, self.warna_tulisan)
        tampilan.blit(gambar_tulisan,(self.x,self.y ))
        return aksi

berhenti = Berhenti(520,580,'PAUSE',14)

#################### OBJEK MENU AWAL ###########################
maingame = Tombol(75, 200, 'PLAY', HIJAU)
keluar = Tombol(325, 200, 'QUIT', MERAH)
warna_bola = Tombol(75, 350, 'BALL', NETRAL)
warna_tangan = Tombol(325, 350, 'STICK', NETRAL)

################### OBJEK MENU UNTUK MEMILIH WARNA #############
merah = Tombol(75, 200, 'RED', MERAH)
kuning = Tombol(325, 200, 'YELLOW', KUNING)
hijau = Tombol(75, 350, 'GREEN', HIJAU)

################# OBJEK UNTUK TOBOLBERAKHIR GAME ################
game_berakhir = Tombol(75, 310, 'EXIT', MERAH)
game_ngulang = Tombol(325, 310, 'RESTART', HIJAU)
game_kembali = Tombol(325, 310, 'BACK', BIRU)

tangan_warna = NETRAL
bola_warna = NETRAL

################# LOOPING UNTUK MENJALANKAN MENU ###############
run = True
while run:

    # MEMBUAT TAMPILAN BACKGROUND
    tampilan.fill(PUTIH)
    tampilan.blit(MUKA_KELOMPOK, (0, 0))

    # KALO MENCET TOMBOL MULAI PROGRAM AKAN KE LOOPING SELANJUTNYA
    if maingame.menampilkan_tombol():
        run = False
    # KOALO MENCET TOMBOL KELUAR MAKA PROGRAM AKAN KELUAR
    if keluar.menampilkan_tombol():
        exit()
    # JIKA MEMILIH BOLA MAKA AKAN MENAMPILKAN MENU WARNA BOLA
    if warna_bola.menampilkan_tombol():
        # MENAMPILKAN MENU PILIHAN BOLA DAN MENGEMBALIKAN WARNA YANG DIPILIH
        run1 = True
        while run1:
            tampilan.fill(PUTIH)
            tampilan.blit(MUKA_KELOMPOK, (0, 0))

            if merah.menampilkan_tombol():
                bola_warna = MERAH
                run1 = False
            if kuning.menampilkan_tombol():
                bola_warna = KUNING
                run1 = False
            if hijau.menampilkan_tombol():
                bola_warna = HIJAU
                run1 = False

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()

            pygame.display.update()

    # MENAMPILKAN MENU PILIHAN GAYUNG DAN MENGEMBALIKAN WARNA YANG DIPILIH
    if warna_tangan.menampilkan_tombol():
        run1 = True
        while run1:
            tampilan.fill(PUTIH)
            tampilan.blit(MUKA_KELOMPOK, (0, 0))

            if merah.menampilkan_tombol():
                tangan_warna = MERAH
                run1 = False
            if kuning.menampilkan_tombol():
                tangan_warna = KUNING
                run1 = False
            if hijau.menampilkan_tombol():
                tangan_warna = HIJAU
                run1 = False

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()

            pygame.display.update()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    pygame.display.update()

########################## OBJEK UNTUK MENAMPILKAN TEMBOK #####################
tembok = Tembok()
tembok.membuat_tembok()

########################## OBEK UNTUK GAYUNG ##################################
pemain = Tangan(tangan_warna)

########################### OBJEK UNTUK BOLA #################################
bola = Bola((pemain.x + (pemain.lebar // 2)), (pemain.y - pemain.tinggi),
            bola_warna)

########################### OBJEK UNTUK BONUS #################################
bonus = Bonus(300, 0)

##################### LOOPING UNTUK MENJALANKAN GAME BREAKOUT ###############
run = True
while run:
    
    tombol_space = pygame.key.get_pressed()

    tampilan.fill(PUTIH)  # MEMBUAT BACKGROUND PUTIH

    tampil_skor = huruf.render(f"Skor: {bola.skor}", True,
                               MERAH)  # MEMBUAT SKOR
    tampilan.blit(tampil_skor,
                  (LEBAR // 2 + 200, TINGGI // 2 + 150))  #MENAMPILKAN SKOR
    tembok.tampil_beton()  #  MENAMPILKAN BETON
    pemain.tampil()  # MENAMPILKAN GAYUNG
    bola.tampil()  # MENAMPILKAN BOLA

    ## jika balok uda ancur 20 kotak dan bola nyentuh gayung maka
    # tembok akan membuat baru tetapi semuanya memiliki kekuatan 2
    if bola.cek_bola_nyentuh and bola.cek_tembok_20:
        tembok.membuat_tembok(2)
        bola.cek_bola_nyentuh = False
        bola.cek_tembok_20 = False

    # KALO BETON UDA ANCUR KELIPATAN 3X
    if bola.bonus_score == True:
        # MENAMPILKAN BONUS
        bonus.tampil()
        bonus.gerak()

        # JIKA BONUS MENYENTUK GAYUNG
        check = bonus.nyentuh
        if check == True:
            bola.skor += 5
            SUARA_KENA_BONUS.play()
            bonus.nyentuh = False
            bola.bonus_score = False
        #JIKA TIDAK MENYENTUH GAYUNG MAKA LETAK BONUS AKAN SEMULA
        if bonus.rect.bottom > TINGGI:
            bonus.letak()
            bola.bonus_score = False

    # MENGECEK APAKAH BOLA NYA MASIH HIDUP
    if bola_hidup:
        #JIKA MASIH MAKA BOLA AKAN BERGERAK
        pemain.gerak()
        selesai = bola.gerak()
        # SAAT BOLA MATI
        if selesai != 0:
            bola_hidup = False

    #MENU PAUSE YANG BERISI PILIHAN MENGULANG ATAU BERHENTI
    if berhenti.menampilkan_tombol() or tombol_space[pygame.K_SPACE]:
        run1 = True
        while run1:
            tampilan.fill(PUTIH)
            tampilan.blit(MUKA_KELOMPOK, (0, 0))

            #MENAMPILKAN SKOR AKHIR
            tampil_skor = huruf.render(f"SKOR ANDA ADALAH : ({bola.skor})",
                                       True, PUTIH)
            tampilan.blit(tampil_skor, (150, 250))

            # SAAT TOMBOL DI TEKAN MAKA AKAN KELUAR
            if game_berakhir.menampilkan_tombol():
                exit()
            #saat tombol di tekan maka game akan merestart dimana game akan mengulang dari awal
            if game_kembali.menampilkan_tombol():
                run1 = False
            
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()

            pygame.display.update()

    # SAAT BOLA MATI
    if not bola_hidup:
        # MENGELUARKAN TAMPILAN GAME OVER
        run1 = True
        while run1:
            tampilan.fill(PUTIH)
            tampilan.blit(MUKA_KELOMPOK, (0, 0))

            tampil_skor = huruf.render(f"GAME BERAKHIR",
                                       True, PUTIH)
            
            tampilan.blit(tampil_skor, (200, 200))

            #MENAMPILKAN SKOR AKHIR
            tampil_skor = huruf.render(f"SKOR ANDA ADALAH : ({bola.skor})",
                                       True, PUTIH)
            tampilan.blit(tampil_skor, (150, 250))

            # SAAT TOMBOL DI TEKAN MAKA AKAN KELUAR
            if game_berakhir.menampilkan_tombol():
                exit()
            #saat tombol di tekan maka game akan merestart dimana game akan mengulang dari awal
            if game_ngulang.menampilkan_tombol():
                tembok.membuat_tembok()
                pemain.tangan_awal(tangan_warna)
                bola.bola_awal((pemain.x + (pemain.lebar // 2)), (pemain.y - pemain.tinggi),bola_warna)
                bola_hidup = True 
                run1 = False

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()

            pygame.display.update()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    pygame.display.update()
pygame.quit()