public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;
  
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data){
      Result<T, E> newRes = new Result<T, E>();
      newRes.data = data;
      return newRes;
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error){
      Result<T, E> newRes = new Result<T, E>();
      newRes.error = error;
      return newRes;
    }
  
    // implement all other functions in the interface
    // returns true if the result data is not null
    public boolean isOk(){
      return this.data != null;
    }

    // returns true if the result Err is not null
    public boolean isErr(){
      return this.error != null;
    }

    // returns the data if the result is Ok, otherwise throws the error
    public T unwrap() throws Exception{
      if (!this.isOk()){
        throw this.error;
      }

      return this.data;
    }

    // returns the data if the result is Ok, otherwise returns the default value
    public T unwrapOrElse(T defaultValue){
      if (!this.isOk()){
        return defaultValue;
      }

      return this.data;
    }

    // returns the data if the result is Ok, otherwise throws the default exception
    public T unwrapOrThrow(Exception defaultException) throws Exception{
      if (!this.isOk()){
        throw defaultException;
      }

      return this.data;
    }
  }