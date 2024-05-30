import java.util.ArrayList;
import java.util.List;

public class DataParser {
    private static List<String> validCountryCodes = new ArrayList<String>(); // Note: Country Code mungkin saja ditambah. Format country code selalu +XX

    public DataParser() {
        validCountryCodes.add("+62");
    }

    public void addCountryCode(String code) {
        validCountryCodes.add(code);
    }

    // Return true apabila phone valid. Panjang phone number yang valid minimal 8 dan maksimal 10 angka setelah country code.
    // Apabila country code tidak ditemukan di list of validCountryCodes, throw InvalidCountryException
    // Apabila panjang nomor tidak valid, throw InvalidPhoneLengthException
    // Tips: Gunakan StringBuilder
    public boolean parsePhone(String phone) throws InvalidCountryException, InvalidPhoneLengthException {
        String countryCode = phone.substring(0, 3);
        String phoneNumber = phone.substring(3);
        boolean validCode = false;

        for(String code : validCountryCodes){
            if(countryCode.equals(code)){
                validCode = true;
                break;
            }
        }

        if(!validCode){
            throw new InvalidCountryException();
        }

        if (phoneNumber.length() < 8 || phoneNumber.length() > 10){
            throw new InvalidPhoneLengthException();
        }

        return true;
    }

    // Return true apabila email valid. Email yang valid adalah email dengan format *@*.*
    // A@gmail.co.com.id adalah email yang valid
    // A.B.C@mail.co adalah email yang valid
    // @gmail.com tidak valid dan akan throw InvalidEmailUserException
    // A@gmail tidak valid dan akan throw InvalidEmailDomainException
    // Algoritma akan mengecek username terlebih dahulu sebelum mengecek domain dari email
    // Dipastikan ada satu @
    public boolean parseEmail(String email) throws InvalidEmailUserException, InvalidEmailDomainException {
        String username = email.substring(0, email.indexOf("@"));
        String domain = email.substring(email.indexOf("@") + 1);
        
        if(username.equals("")){
            throw new InvalidEmailUserException();
        }else{
            if(!domain.contains(".")){
                throw new InvalidEmailDomainException();
            }else if(domain.substring(0, 1).equals(".")){
                throw new InvalidEmailDomainException();
            }else if(domain.substring(domain.indexOf(".")).equals(".")){
                throw new InvalidEmailDomainException();
            }
        }

        return true;
    }
}
