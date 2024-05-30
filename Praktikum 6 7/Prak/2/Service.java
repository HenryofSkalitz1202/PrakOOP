import java.util.ArrayList;
import java.util.List;

public class Service {
    private String servicePhone;
    private String serviceName;
    private String serviceEmail;
    private IMessageSender messageSender;
    private List<User> users;


    public Service(String serviceName, String serviceEmail, String servicePhone) {
        // Inisialisasi service dengan serviceName, serviceEmail, dan servicePhone, users diinisialisasi dengan list kosong
        this.servicePhone = servicePhone;
        this.serviceName = serviceName;
        this.serviceEmail = serviceEmail;
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        // Tambahkan user ke dalam list users
        this.users.add(user);

    }

    public void sendMessage(String message){
        // Kirim pesan ke semua user dengan isi pesan message
        // Panggil method sendMessage dari messageSender
        // Cek apakah user memiliki email, jika ada kirim email, dst. Email, device, phone yang kosong tidak perlu dikirim. Data yang kosong ditandai dengan ""
        for(User user : this.users){
            if(user.getEmail() != ""){
                this.messageSender = new EmailMessageSender(serviceEmail);
                this.messageSender.sendMessage(user, message);
            }

            if(user.getDevice() != ""){
                this.messageSender = new PushNotifMessageSender(serviceName);
                this.messageSender.sendMessage(user, message);
            }

            if(user.getPhone() != ""){
                this.messageSender = new SMSMessageSender(servicePhone);
                this.messageSender.sendMessage(user, message);
            }
        }
    }
}
