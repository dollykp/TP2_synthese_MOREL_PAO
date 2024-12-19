# TP2_synthese_MOREL_PAO

The objectives of this lab is to develop a TFTP client using RFC specifications and Wireshark captures.

Indications : n in the "gettftpn.c" files means that it's the n-th question.
(example : gettftp2.c is the code for the 2nd question)

1)
First, in order to obtain the server's address, we re-used the code previously used in the TDm3, with the getaddrinfo() function.

2) 
To test the function, we put in the terminal the following command :
./gettftp3 127.0.0.1 1069 zeros256

127.0.0.1 is the address of the server, 1069 is the port's number and zeros256 the file's name.

![alt text](question3.jpg)

La fonction getaddrinfo retourne 0 donc il n'y a pas d'erreurs. Les valeurs de ai_family, ai_protocol et ai_socket retournent les bonnes valeurs.