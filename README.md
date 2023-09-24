# GDSC-LAST-PROJECT
Repository ini berisi Program yang dibuat untuk memenuhi kebutuhan Sertifikasi GDSC ITB

NOTE 1:
    - src.cpp file code
    - blackjack-algo.exe file yang akan digunakan

NOTE 2:
    - Input ACE as 1
    - Input Jack, Queen, King as 10
    - Input value only 

Program ini adalah program interaktif yang akan membantu mengeluarkan probabilitas terbaik selama bermain blackjack, dengan mempertimbangkan:
    - Kartu yang sudah keluar
    - Kartu yang ada di tangan pemain
    - Kartu yang ada di tangan  bandar
Banyak alternatif cara yang bisa digunakan untuk mengeluarkan probabilitas ketika bermain blackjack, mulai dari 
  - program pre-computed yang memiliki kompleksitas O(1) ketika dijalankan namun O(10^18) ketika di compile,
  - program yang setiap akan generate probability stand akan melakukan rekursi sebanyak +- 2^42 kali
  - program yang mengandalkan matematika sederhana
Berhubung developer tidak memiliki quantum computer, maka developer mengandalkan teorema bayes dan conditional probability untuk melakukan komputasi. Program akan meminta banyak input selama berjalan sebagai bahan pembelajaran dan data untuk mengambil keputusan, Lalu mengeluarkan probabilitas ketika giliran pemain.


--Selamat bermain para penjudi.
