public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws Exception{
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */

        if (this.email.length() == 0) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        if (this.email.indexOf('@') == -1 || this.email.indexOf('@') != this.email.lastIndexOf('@')) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        } else if (this.email.indexOf('@') == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }
        int idx = this.email.indexOf('@');

        if (this.email.indexOf('.', idx) == -1) {
            throw new InvalidDomainException();
        } else if (this.email.indexOf('.', idx) != this.email.lastIndexOf('.')) {
            throw new InvalidDomainException();
        } else if (this.email.indexOf('.', idx) == (idx + 1)) {
            throw new InvalidDomainException();
        } else if (this.email.indexOf('.', idx) == (this.email.length() - 1)) {
            throw new InvalidDomainException();
        }

        return true;
    }

}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class InvalidDomainException extends Exception{
    // Implementasi custom message InvalidDomainException
    // Return pesan multak berisi: "Email harus memiliki domain yang valid
    public InvalidDomainException(){
        super("Email harus memiliki domain yang valid");
    }

    public String getMessage() {
        return super.getMessage();
    }
}