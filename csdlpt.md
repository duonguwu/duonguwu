# Phân chia đồ án 
-    **Dương với Đạt:**  Kết nối 2 máy
-    **Huy với Duy:** Code các câu lệnh SQL

**Làm bài 3, kết nối 2 chiều để tham khảo, đề thi sẽ tương tự**
  **Link:** https://courses.uit.edu.vn/pluginfile.php/394683/mod_resource/content/1/%5B2022%5DTH_CSDLPT_Buoi02.pdf

## 1. Tạo bảng (Huy với Duy)
 - Tiến hành viết code SQL tạo bảng như theo đề đã cho, **học kĩ** cấu trúc code tạo bảng trong Oracle/Sql plus. Kiểu dữ liệu từng trường.
 - Tự viết trước Trigger và Procedure, không biết viết thì xem chatgpt rồi học thuộc nhé, ráng mà hiểu.
## Lời giải ví dụ:
## Các bước thực hiện:
### 1. Tạo user admin làm quản lý:
- CREATE USER ADMIN IDENTIFIED BY your_password;
### Đăng nhập vào user admin để tạo table: 
- CONNECT ADMIN/your_password;
```SQL
CREATE TABLE KHACHHANG (
    MaKH NUMBER PRIMARY KEY,
    TenKH VARCHAR2(50),
    TongTien NUMBER
);

CREATE TABLE CHINHANH (
    MaCN NUMBER PRIMARY KEY,
    TenCN VARCHAR2(50)
);

CREATE TABLE GIAODICH (
    MaGD NUMBER PRIMARY KEY,
    MaCN NUMBER,
    MaKH NUMBER,
    SoTienGD NUMBER,
    LoaiGD CHAR(1)
);
```
### 3. Tạo nhóm quyền role_GIAODICH và gán quyền truy vấn và thêm dữ liệu:
```SQL
CREATE ROLE role_GIAODICH;

GRANT SELECT, INSERT ON GIAODICH TO role_GIAODICH;
GRANT SELECT ON KHACHHANG TO role_GIAODICH;
```

### 4. Tạo user GUEST và gán nhóm quyền role_GIAODICH cho user:
```SQL
CREATE USER GUEST IDENTIFIED BY your_password;
GRANT role_GIAODICH TO GUEST;
```
### 5. Tạo kết nối giữa các hệ quản trị cơ sở dữ liệu của các chi nhánh sử dụng user GUEST:
```SQL
CREATE DATABASE LINK CHINHANH_LINK CONNECT TO GUEST IDENTIFIED BY your_password USING 'CHINHANH';
```
### 6. Tạo Trigger với Procedure 
Trigger
```SQL
CREATE OR REPLACE TRIGGER CapNhatGD
AFTER INSERT ON GIAODICH
FOR EACH ROW
BEGIN
    IF :NEW.LoaiGD = 'G' THEN
        UPDATE KHACHHANG SET TongTien = TongTien + :NEW.SoTienGD WHERE MaKH = :NEW.MaKH;
    ELSIF :NEW.LoaiGD = 'R' THEN
        UPDATE KHACHHANG SET TongTien = TongTien - :NEW.SoTienGD WHERE MaKH = :NEW.MaKH;
    END IF;
END;
/
```
Procedure
```SQL
CREATE OR REPLACE PROCEDURE RutTien(MaKH IN NUMBER, SoTienGD IN NUMBER)
AS
BEGIN
    -- Thêm logic kiểm tra và thực hiện giao dịch rút tiền
END;
/

CREATE OR REPLACE PROCEDURE GuiTien(MaKH IN NUMBER, SoTienGD IN NUMBER)
AS
BEGIN
    -- Thêm logic kiểm tra và thực hiện giao dịch gửi tiền
END;
/
```
## Thực hiện kết nối:
- Tắt tường lửa, chạy cmd, chạy notepad bằng quyền của admin.
- Ở 2 máy, bắt đầu sửa file host ***(system32/driver/etc)***. Thêm địa chỉ ip vào cả 2 máy:
      Để ip máy B ở trên máy A
### Máy A:
1. Vào ADMIN, sửa file listener.ora: Sửa host thành mayB -> cut dòng này đưa lên trên
2. Sửa tnsname: copy block ORCL, 
      
