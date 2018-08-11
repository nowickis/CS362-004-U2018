

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.HashMap;
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
       HashMap<String, Boolean> urls = new HashMap<String, Boolean>();
       
       urls.put("http://www.something.com", true);
       urls.put("http://www.something.org", true);
       urls.put("http://www.something.net", true);
       urls.put("http://www.something.uk", true);
       urls.put("http://www.Something.uk", true);

       //port
       urls.put("http://snowicki-7040.infogix.com:8080", true);
       urls.put("http://snowicki-7040.infogix.com|8080", false);
       //path
       urls.put("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html", true);
       urls.put("http://snowicki-7040.infogix.com:8080/cafe/%%%% /index.html", false);
       //query string
       urls.put("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html?dev=true&tenantId=infogix.com", true);
       urls.put("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html?&&&/&&/&dev=======truetenantId=infogix.com", false);
       //fragment
       urls.put("http://snowicki-7040.infogix.com:8080/cafe/desktop/index.html?dev=true&tenantId=infogix.com#dashboard/501492", true);

       for(HashMap.Entry<String, Boolean> entry: urls.entrySet()){
    	   Boolean passed = urlVal.isValid(entry.getKey()) == entry.getValue();
    	   String testMessage = 
    			   (passed ? "PASS: " : "FAIL: ")
    			   + entry.getKey()
    			   + " is "
    			   + (passed ? "correctly" : "incorrectly")
    			   + " considered "
    			   + (entry.getValue() ? "valid" : "invalid");
    	   System.out.println(testMessage);
       }


   }
   //authorities are good. ports and paths are not; query strings are good; fragments are good
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      
       HashMap<String, Boolean> urls = new HashMap<String, Boolean>();
       //path partition - paths are broken
       urls.put("http://snowicki-7040.infogix.com/cafe/desktop/index.html", true);
       //port partition - ports are broken
       urls.put("http://snowicki-7040.infogix.com:8080", true);
       //query string partition
       urls.put("http://snowicki-7040.infogix.com?dev=true&tenantId=infogix.com", true);
       //fragment partition
       urls.put("http://snowicki-7040.infogix.com#dashboard/501492", true);
       
       for(HashMap.Entry<String, Boolean> entry: urls.entrySet()){
    	   Boolean passed = urlVal.isValid(entry.getKey()) == entry.getValue();
    	   String testMessage = 
    			   (passed ? "PASS: " : "FAIL: ")
    			   + entry.getKey()
    			   + " is "
    			   + (passed ? "correctly" : "incorrectly")
    			   + " considered "
    			   + (entry.getValue() ? "valid" : "invalid");
    	   System.out.println(testMessage);
       }
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       HashMap<String, Boolean> authorities = new HashMap<>();
       HashMap<String, Boolean> ports = new HashMap<>();
       HashMap<String, Boolean> paths = new HashMap<>();
       HashMap<String, Boolean> queryStrings = new HashMap<>();
       HashMap<String, Boolean> fragments = new HashMap<>();

       //from tests above, we know that only http is going to work, so no use testing other schemes
       String httpScheme = "http://";

       authorities.put("www.a.com", true);
       authorities.put("www.A.com", true);
       authorities.put("WWW.hello.com", true);
       authorities.put("www.hello.org", true);
       authorities.put("www.world.io", true);
       authorities.put("www.123.us", true);

       StringBuilder longOne = new StringBuilder(1004);
       int i = 0;
       while(i<1000){
           longOne.append("a");
           i++;
       }
       longOne.append(".com");
        String longOneString = longOne.toString();
       authorities.put(longOneString, true);

       ports.put("", true);
       ports.put(":8080", true);
       ports.put(":1234", true);
       ports.put("|0039", false);
       ports.put(":im_not_a_port", false);

       paths.put("/a/b/index.html", true);
       paths.put("", true);
       paths.put("/", true);
       paths.put("/A", true);
       paths.put("^^^not^a^path", false);

       queryStrings.put("?", true);
       queryStrings.put("", true);
       queryStrings.put("?me=this", true);
       queryStrings.put("?me=this&this=me", true);

       fragments.put("", true);
       fragments.put("#", true);
       fragments.put("#frag", true);
       fragments.put("#frag=ment", true);

       i = 0;
       System.out.println("Automated testing\n");
       
       for (HashMap.Entry<String, Boolean> eAuth : authorities.entrySet()) {
    	   String auth = eAuth.getKey();
    	   Boolean authExpect = eAuth.getValue();
    	   
    	   for (HashMap.Entry<String, Boolean> ePort : ports.entrySet()) {
	    	   String port = ePort.getKey();
	    	   Boolean portExpect = ePort.getValue();
	    	   
	    	   for (HashMap.Entry<String, Boolean> ePath : paths.entrySet()) {
	    		   String path = ePath.getKey();
	    		   Boolean pathExpect = ePath.getValue();
	    		   
	    		   for (HashMap.Entry<String, Boolean> eQuery : queryStrings.entrySet()) {
	    			   String query = eQuery.getKey();
	    			   Boolean queryExpect = eQuery.getValue();
		    		   
		    		   for (HashMap.Entry<String, Boolean> eFrag : fragments.entrySet()) {
		    			   String frag = eFrag.getKey();
		    			   Boolean fragExpect = eFrag.getValue();
		    			   
		    			   // Actual testing!
		    			   String testUrl = httpScheme + auth + port + path + query + frag;
		    			   Boolean expected = authExpect && portExpect && pathExpect && queryExpect && fragExpect;
		    			   Boolean passed = urlVal.isValid(testUrl) == expected;
		    			   
		    			   String testMessage =
		    					   (passed ? "PASS: " : "FAIL: ")
		    					   + testUrl
		    					   + " is "
		    					   + (passed ? "correctly" : "incorrectly")
		    					   + " considered "
		    					   + (expected ? "valid" : "invalid");
		    			   System.out.println(testMessage);
		    		   }
	    		   }
	    	   }
    	   }
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
