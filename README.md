Hospital/Clinic Management System


Ý tưởng:

Code sẽ hoạt động như sau:

Khi chạy sẽ hiện ra 1 menu lựa chọn (lựa chọn sẽ tùy người dùng nhập)

-------MENU---------
1. Quản lý bệnh nhân
2. Quản lý bác sĩ
3. Quản lý ý tá
4. Đặt lịch hẹn
0. Thoát

Sau nó tùy vào lựa chọn của người dùng mà hiển thị chi tiết từng phần. Ví dụ:
Người dùng nhập vào số 2, code sẽ hiển thị tiếp

-------BAC_SI---------
1. Hiển thị thông tin bác sĩ
2. Thêm bác sĩ
3. Xóa bác sĩ
4. Tìm kiếm bác sĩ (tìm theo IDbacsi)
0. Thoát

Nếu nhập số ko hợp lệ thì chương trình sẽ hiển thị ra text nhập sai gì gì đó rồi
tiếp tục quay lại menu để chọn lại, đến khi chọn 0 r thì mới quay lại menu chính.

Tương tự với các phần khác như quản lý y tá, đặt lịch hẹn. Các thành phần lựa chọn
ở menu dựa vào attribute ở các class để lập nên. Nếu nghĩ ra thêm các phần cho menu
thì cứ chỉnh sửa rồi gửi lên nhóm, đồng thuận thêm thì sẽ thêm hay những phần nào
ko hợp lý thì có thể xóa. 


Person (abstract)
 ├── Staff
 │    ├── Doctor
 │    └── Nurse
 └── Patient
 Appointment
 ├── CheckupAppointment
 └── SurgeryAppointment
TreatmentType
 ├── Medication
 ├── SurgeryTreatment
 └── Therapy


