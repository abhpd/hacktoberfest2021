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