@RestController
public class HelloWorld {
    @RequestMapping("/hello")
    public String hello(){
        return "Hello World!";
    }
}