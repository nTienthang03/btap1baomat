# btap1baomat
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
Caesar
Affine
Hoán vị
Vigenère
Playfair
Với mỗi phương pháp, hãy tìm hiểu:

B Tên gọi
Thuật toán mã hoá, thuật toán giải mã
Không gian khóa
Cách phá mã (mà không cần khoá)
Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
# Bài Làm 
1. Mã Caesar (Caesar Cipher)
Tên gọi
Mã Caesar, còn gọi là mã dịch chuyển (Shift Cipher), là một trong những phương pháp mã hóa cổ điển đơn giản nhất, được đặt tên theo Julius Caesar, người đã sử dụng nó để bảo vệ thông tin quân sự.
Thuật toán mã hóa

Giả sử bảng chữ cái tiếng Anh (A-Z, 26 chữ cái, không phân biệt hoa/thường cho đơn giản).
Mã hóa mỗi chữ cái bằng cách dịch chuyển nó k vị trí trong bảng chữ cái (mod 26).
Công thức: E(x) = (x + k) mod 26, nơi x là vị trí chữ cái (A=0, B=1, ..., Z=25).
Các ký tự không phải chữ cái giữ nguyên.

Thuật toán giải mã

Giải mã bằng cách dịch ngược: D(y) = (y - k) mod 26.

Không gian khóa

Khóa k có thể từ 1 đến 25 (k=0 là bản rõ, thường loại trừ).
Không gian khóa: 25.

Cách phá mã (mà không cần khóa)

Brute force: Thử tất cả 25 giá trị k và kiểm tra văn bản giải mã có ý nghĩa (phân tích tần suất chữ cái phổ biến như E, T, A trong tiếng Anh).
<img width="1919" height="1073" alt="image" src="https://github.com/user-attachments/assets/452bab24-a3b2-4466-bb5c-f0f15724c8d5" />
html

mã hóa 

<img width="1888" height="569" alt="image" src="https://github.com/user-attachments/assets/42712d7b-598a-4435-96ef-23d39ab9b5e5" />

giải mã 

<img width="1212" height="493" alt="image" src="https://github.com/user-attachments/assets/ee23b3dc-1b49-40cd-8a08-7e2383b59569" />
# 2. Mã Affine (Affine Cipher)
Tên gọi
Mã Affine, là một dạng mã hóa tuyến tính, kết hợp nhân và cộng modulo.
Thuật toán mã hóa

Công thức: E(x) = (a * x + b) mod m, nơi m=26 (bảng chữ cái A-Z), x là vị trí chữ cái (A=0,...), a phải nguyên tố cùng nhau với m (gcd(a,26)=1), b từ 0-25.
Các ký tự không phải chữ cái giữ nguyên.

Thuật toán giải mã

Tìm nghịch đảo modulo của a: a_inv sao cho (a * a_inv) mod 26 = 1.
D(y) = a_inv * (y - b) mod 26.

Không gian khóa

a: Có 12 giá trị (phi(26)=12: 1,3,5,7,9,11,15,17,19,21,23,25).
b: 26 giá trị.
Tổng: 12 * 26 = 312.

Cách phá mã (mà không cần khóa)

Brute force: Thử tất cả 312 khóa.
Hoặc phân tích tần suất chữ cái để đoán a và b (ví dụ, ánh xạ chữ cái phổ biến).
C++
<img width="1836" height="700" alt="image" src="https://github.com/user-attachments/assets/c4d04118-5d8e-4e34-9a7d-59b0d71a0349" />
html
mã hóa 
<img width="1919" height="634" alt="image" src="https://github.com/user-attachments/assets/5a0f1d6b-671c-49aa-ab80-16971a9461c0" />
giải mã 
<img width="1256" height="668" alt="image" src="https://github.com/user-attachments/assets/4f1522bf-d6f3-492a-b41c-83e653f486f8" />


# 3. Mã Hoán vị (Permutation Cipher / Transposition Cipher)
Tên gọi
Mã Hoán vị, còn gọi là Mã Chuyển vị (Transposition Cipher), ví dụ phổ biến là Columnar Transposition.
Thuật toán mã hóa

Sử dụng khóa là một chuỗi số (hoán vị cột), ví dụ khóa "3142" cho 4 cột.
Viết văn bản vào lưới theo hàng, rồi đọc theo thứ tự cột theo khóa.
Điền padding nếu cần (ví dụ 'X').

Thuật toán giải mã

Sắp xếp lưới theo thứ tự khóa ngược, viết theo cột, đọc theo hàng.

Không gian khóa

Với độ dài khóa n (số cột), không gian là n! (số hoán vị).

Cách phá mã (mà không cần khóa)

Ước lượng độ dài khóa bằng cách tìm khoảng cách lặp lại.
Thử sắp xếp cột và kiểm tra văn bản có ý nghĩa.
C++
<img width="1830" height="738" alt="image" src="https://github.com/user-attachments/assets/d7435957-16f3-437f-8e45-37024291159d" />
html 
mã hóa 

<img width="963" height="412" alt="image" src="https://github.com/user-attachments/assets/3ddaeb32-56d3-47f3-b678-d8043d2ef7cb" />

giải mã 
<img width="1330" height="559" alt="image" src="https://github.com/user-attachments/assets/a23b59f0-9f5e-4613-82a5-567ab0e836b5" />

C++
<img width="1817" height="670" alt="image" src="https://github.com/user-attachments/assets/35f827f4-d0fc-40d6-9d47-d6a1844a845d" />
html 



# 4 Mã Vigenère (Vigenère Cipher)
Tên gọi
Mã Vigenère, là mã đa bảng (polyalphabetic), sử dụng khóa lặp lại.
Thuật toán mã hóa

Khóa là chuỗi chữ cái, lặp lại để khớp độ dài văn bản.
Mỗi chữ cái: E(x_i) = (x_i + k_i) mod 26, nơi k_i là vị trí khóa.

Thuật toán giải mã

D(y_i) = (y_i - k_i) mod 26.

Không gian khóa

Với độ dài khóa l, không gian là 26^l (rất lớn nếu l dài).

Cách phá mã (mà không cần khóa)

Kasiski examination: Tìm độ dài khóa bằng cách tìm khoảng cách lặp lại chuỗi.
Sau đó, phân tích tần suất từng nhóm để đoán khóa.
C++
<img width="1771" height="660" alt="image" src="https://github.com/user-attachments/assets/2a316633-c23d-480c-80dc-44d99db90892" />

HTMl 
mã hóa 
<img width="1319" height="508" alt="image" src="https://github.com/user-attachments/assets/15c3e2d7-cae8-48c1-a9ce-7ecea584ee01" />
giải mã 
<img width="1532" height="575" alt="image" src="https://github.com/user-attachments/assets/fb7008c6-b0a4-41e7-be7a-26dabb2b226c" />

# 5. Mã Playfair (Playfair Cipher)
Tên gọi
Mã Playfair, sử dụng bảng 5x5 chữ cái (kết hợp I/J).
Thuật toán mã hóa

Tạo bảng 5x5 từ khóa (loại trùng, thêm chữ cái còn lại, I/J chung).
Mã hóa cặp chữ cái: Nếu cùng hàng, dịch phải; cùng cột, dịch xuống; khác, hình chữ nhật.
Thêm 'X' nếu cặp giống hoặc lẻ.

Thuật toán giải mã

Ngược lại: Dịch trái cho hàng, lên cho cột, hình chữ nhật giống.

Không gian khóa

Số cách sắp xếp bảng: Khoảng 25! / 2 (vì I/J chung), rất lớn.

Cách phá mã (mà không cần khóa)

Phân tích tần suất cặp chữ cái (digraphs), đoán bảng từ cặp phổ biến như TH, HE.

Cài đặt bằng C++
<img width="1761" height="649" alt="image" src="https://github.com/user-attachments/assets/c248ada8-703d-41af-bea3-1830a6b44e06" />
html
mã móa
<img width="1008" height="364" alt="image" src="https://github.com/user-attachments/assets/c6c30b0a-737d-4d00-b70c-485acdde2bbe" />

giải mã 
<img width="1055" height="490" alt="image" src="https://github.com/user-attachments/assets/fe2e78e4-ee8a-43bb-a0c1-7bb68eb22902" />






