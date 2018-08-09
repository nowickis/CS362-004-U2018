

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       //this should pass, and it passes
       //assertTrue(urlVal.isValid("http://www.google.com"));
       if (urlVal.isValid("http://www.google.com")) {
           System.out.println("http://www.google.com is correctly considered valid\n");
       } else {
           System.out.println("http://www.google.com is incorrectly considered invalid\n");
       }

       //this should fail, but it passes
       //assertTrue(urlVal.isValid("http://www..google.com"));
       if (urlVal.isValid("http://www..google.com")) {
           System.out.println("http://www..google.com is incorrectly considered valid\n");
       } else {
           System.out.println("http://www..google.com is correctly considered invalid\n");
       }

       //this should pass, but it fails
       //assertTrue(urlVal.isValid("https://www.google.com"));
       boolean httpsIsTestable = true;
       try {
           urlVal.isValid("https://www.google.com");
       } catch (ExceptionInInitializerError e) {
           System.out.println("Bug preventing https://www.google.com from being fully tested\n" + e + "\n");
           httpsIsTestable = false;
       }
       if (httpsIsTestable) {
           if (urlVal.isValid("https://www.google.com")) {
               System.out.println("https://www.google.com is correctly considered valid\n");
           } else {
               System.out.println("https://www.google.com is incorrectly considered invalid\n");
           }
       }

       //this should pass, but it fails
       //assertTrue(urlVal.isValid("ftp://access.engr.oregonstate.edu"));
       boolean ftpIsTestable = true;
       try {
           urlVal.isValid("ftp://access.engr.oregonstate.edu");
       } catch (ExceptionInInitializerError | NoClassDefFoundError e) {
           System.out.println("Bug preventing ftp://access.engr.oregonstate.edu from being fully tested\n" + e + "\n");
           ftpIsTestable = false;
       }
       if (ftpIsTestable) {
           if (urlVal.isValid("ftp://access.engr.oregonstate.edu")) {
               System.out.println("ftp://access.engr.oregonstate.edu is correctly considered valid\n");
           } else {
               System.out.println("ftp://access.engr.oregonstate.edu is incorrectly considered invalid\n");
           }
       }

       //this should pass, but it fails
       //assertTrue(urlVal.isValid("file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf"));
       boolean fileIsTestable = true;
       try {
           urlVal.isValid("file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf");
       } catch (ExceptionInInitializerError | NoClassDefFoundError e) {
           System.out.println("Bug preventing file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf from being fully tested\n" + e + "\n");
           fileIsTestable = false;
       }
       if (fileIsTestable) {
           if (urlVal.isValid("file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf")) {
               System.out.println("file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf is correctly considered valid\n");
           } else {
               System.out.println("file:///C:/Users/snowicki/Desktop/TMHandbook_v1.5_4Jan18.pdf is incorrectly considered invalid\n");
           }
       }


   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing
       //http partition
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       ArrayList<String> urls = new ArrayList<>();
       urls.add("http://www.something.com");
       urls.add("http://www.something.org");
       urls.add("http://www.something.net");
       urls.add("http://www.something.uk");
       urls.add("http://www.Something.uk");

       //port
       urls.add("http://snowicki-7040.infogix.com:8080");
       //path
       urls.add("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html");
       //query string
       urls.add("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html?dev=true&tenantId=infogix.com");
       //fragment
       urls.add("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html?dev=true&tenantId=infogix.com#dashboard/501492");

       for(String url: urls){
           if(urlVal.isValid(url)){
               System.out.println(url + " is correctly considered valid.\n");
           } else {
               System.out.println(url + " is incorrectly considered invalid.\n");
           }
       }


   }
   //authorites are good. ports and paths are not; query strings are good; fragments are good
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       ArrayList<String> urls = new ArrayList<>();
       //path partition - paths are broken
       urls.add("http://snowicki-7040.infogix.com/cafe/desktop/index.html");
       //port partition - ports are broken
       urls.add("http://snowicki-7040.infogix.com:8080");
       //query string partition
       urls.add("http://snowicki-7040.infogix.com?dev=true&tenantId=infogix.com");
       //fragment partition
       urls.add("http://snowicki-7040.infogix.com#dashboard/501492");
       for(String url: urls){
           if(urlVal.isValid(url)){
               System.out.println(url + " is correctly considered valid.\n");
           } else {
               System.out.println(url + " is incorrectly considered invalid.\n");
           }
       }

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       ArrayList<String> schemes = new ArrayList<>();
       ArrayList<String> authorites = new ArrayList<>();
       ArrayList<String> ports = new ArrayList<>();
       ArrayList<String> paths = new ArrayList<>();
       ArrayList<String> queryStrings = new ArrayList<>();
       ArrayList<String> fragments = new ArrayList<>();

       //from tests above, we know that only http is going to work, so no use testing other schemes
       schemes.add("http://");

       authorites.add("www.a.com");
       authorites.add("www.A.com");
       authorites.add("WWW.hello.com");
       authorites.add("www.hello.org");
       authorites.add("www.world.io");
       authorites.add("www.123.us");

       StringBuilder longOne = new StringBuilder(1000);
       int i = 0;
       while(i<1000){
           longOne.append("a");
           i++;
       }
       longOne.append(".com");
        String longOneString = longOne.toString();
       authorites.add(longOneString);

       ports.add("");
       ports.add(":8080");
       ports.add(":1234");

       paths.add("/a/b/index.html");
       paths.add("");
       paths.add("/");
       paths.add("/A");

       queryStrings.add("?");
       queryStrings.add("");
       queryStrings.add("?me=this");
       queryStrings.add("?me=this&this=me");

       fragments.add("");
       fragments.add("#");
       fragments.add("#frag");
       fragments.add("#frag=ment");

       i = 0;
       System.out.println("Automated testing\n");
       while(i < 1000){
           Random rand = new Random();
           int  randomAuthority = rand.nextInt(authorites.size());
           int  randomPort = rand.nextInt(ports.size());
           int  randomPath = rand.nextInt(paths.size());
           int  randomQueryString = rand.nextInt(queryStrings.size());
           int  randomFragment = rand.nextInt(fragments.size());
           String url = schemes.get(0) + authorites.get(randomAuthority) + ports.get(randomPort) + paths.get(randomPath) +
                        queryStrings.get(randomQueryString) + fragments.get(randomFragment);
           if(urlVal.isValid(url)){
               System.out.println(url + " is correctly considered valid.\n");
           } else {
               System.out.println(url + " is incorrectly considered invalid.\n");
           }
           i++;
       }

   }
   
   public static void main(String[] argv) {

	  UrlValidatorTest fct = new UrlValidatorTest("url test");
      //fct.setUp();
      //fct.testIsValid();
      //fct.testIsValidScheme();
	  fct.testManualTest();
	  fct.testYourFirstPartition();
	  fct.testYourSecondPartition();
	  fct.testIsValid();
   }
   


}
