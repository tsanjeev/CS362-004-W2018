

import java.util.Arrays;

import junit.framework.TestCase;

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
	  // UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String [] schemes = {"https","http", "ftp", "h3t",
			     ""};
	   
	   //UrlValidator urlVal = new UrlValidator(schemes, 0);
	   UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("\n\nMANUAL TESTING");
       
        System.out.println("http://www.oregonstate.com/test1/");              
        System.out.println("Returned: " + urlVal.isValid("http://www.oregonstate.com/test1/") + " Expected: true");
       
       System.out.println("Testing http://www.oregonstate.edu");
       System.out.println("Returned: " + urlVal.isValid("http://www.oregonstate.edu") + "  Expected: true");
   
       System.out.println("Testing http://www.oregonstate");
       System.out.println("Returned: " + urlVal.isValid("http://www.oregonstate") + " Expected: false");
   
       System.out.println("Testing http://www.google.com:");
       System.out.println("Returned: " + urlVal.isValid("http://www.google.com:") + " Expected: false");
       
       System.out.println("Testing https://www.google.com");
       System.out.println("Returned: " + urlVal.isValid("https://www.google.com") + " Expected: true");
       
       System.out.println("Testing http://google.com");
       System.out.println("Returned: " + urlVal.isValid("http://google.com") + " Expected: true");
       
       System.out.println("Testing http:/www.google.com");
       System.out.println("Returned: " + urlVal.isValid("http:/www.google.com") + " Expected: false");
       
       System.out.println("Testing http://www.google.com:65535");
       System.out.println("Returned: " + urlVal.isValid("http://www.google.com:65535") + " Expected: true");
       
       System.out.println("Testing http://www.1.2.3.4");
       System.out.println("Returned: " + urlVal.isValid("http://www.1.2.3.4") + " Expectred: false");
       System.out.println();
	   
   }
	public void testYourFirstPartition(){
		String[] valid = {"http://",
								"ftp://",
								"https://",
								"file://",
								""};
		String[] invalid = {"htttp://",
									"ftps://",
									"http::/",
									"http//",
									"http://",
									"://",
									"//"};
		String pre = "";
		String post = "www.google.com";
		int pass = 0;
		int total = 0;
		//UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);
		UrlValidator urlVal = new UrlValidator();
		System.out.println("Testing Valid Schemes");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
					
		System.out.println("Testing Invalid Schemes");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
			
			
	public void testYourSecondPartition(){
		String[] valid = {"google.com",
								"0.0.0.0",
								"www.google.com",
								"255.255.255.255",
								"amazon.com",
								"www.amazon.com"
		};
		String[] invalid = {"ww.google.com",
									"256.256.256.256",
									".com",
									"google",
									""
		};
																							
		String pre = "http://";
		String post = "";
		int pass = 0;
		int total = 0;
		UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);
				
		System.out.println("Testing Valid Authorities");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
		System.out.println("Testing Invalid Authorities");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
				
			
	/* https://en.wikipedia.org/wiki/Port_%28computer_networking%29
	* ports should range from 0 to 65535 inclusive*/
			
	public void testYourThirdPartition(){
		String[] valid = {"",
								":80",
								":100",
								":2000",
								":65535",
		};
		String[] invalid = {":100000",
									":65636",
									":wrong",
									":32wrong"
		};
		String pre = "http://www.google.com";
		String post = "";
		int pass = 0;
		int total = 0;
		UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);
				
		System.out.println("Testing Valid Ports");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
				
		System.out.println("Testing Invalid Ports");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
																						
	public void testYourFourthPartition(){
		String[] valid = {"",
								"/test1",
								"/$23hljhljl/",
								"/test1/",
								"/test1/file",
								"t213"
		};
		String[] invalid = {"/..",
									"/../",
									"/..//file",
									"/test1//file"
		};
		String pre = "http://www.google.com";
		String post = "";
		int pass = 0;
		int total = 0;
		UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);
		
		System.out.println("Testing Valid Paths");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
		System.out.println("Testing Invalid Paths");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
	
	public void testYourFifthPartition(){
		String[] valid = {"/test1",
								"/$23",
								"/a96/file",
								"/test1/file",
								"/test1//file",
								"",
								"/test1/"
		};
		String[] invalid = {"/..",
									"/../",
									"/../file",
									"/#/file",
									"/..//file"
		};
		String pre = "http://www.google.com";
		String post = "";
		int pass = 0;
		int total = 0;
		UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);
		
		System.out.println("Testing Valid Path Options");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
		System.out.println("Testing Invalid Path Options");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
	
	public void testYourSixthPartition(){
		String[] valid = {"?fuzzy=llama",
								"?action=view",
								"?action=edit&mode=up"
		};
		String[] invalid ={"!action=edit&mode=up",
								"&action=view",
								"$action=view"
		};
		String pre = "http://www.google.com";
		String post = "";
		int pass = 0;
		int total = 0;
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		
		System.out.println("Testing Valid Queries");
		for(int i = 0; i < valid.length; i++){
			total++;
			if(urlVal.isValid(pre + valid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + valid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + valid[i] + post);
			}
		}
		System.out.println();
		System.out.println("Testing Invalid Queries");
		for(int i = 0; i < invalid.length; i++){
			total++;
			if(!urlVal.isValid(pre+invalid[i] + post)){
				pass++;
				System.out.println("PASSED: " + pre + invalid[i] + post);
			}
			else{
				System.out.println("FAILED: " + pre + invalid[i] + post);
			}
		}
		System.out.println(pass + " tests passed out of " + total + " total tests");
		System.out.println();
	}
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   String [] schemes = {"http://", "ftp://", "h3t://",
			   "3ht://", "http:/", "http:", "http/", "://", ""};
       String [] badSchemes = {"3ht://", "http:/", "http:", "http/", "://"};
       
       String [] auth = {"www.google.com", "0.0.0.0", "255.255.255.255", "256.256.256.256", "1.2.3.4.5", "255.com"};
       String [] badAuth = {"256.256.256.256", "1.2.3.4.5"};
       
       String [] port = {":80", ":0", ":-1", ":b5a", ""};
       String [] badPort = {":-1", ":b5a"};
       
       String [] path = {"","/home", "/../"};
       String [] badPath = {"/../"};
       
       String [] query = {"?action=view"};
       String [] badQuery = {"action=?view"};
       
       
       System.out.println("Starting Random Unit Testing...");
      
       int testFails = 0;
       int totalRuns = 10;
       
       //UrlValidator urlVal = new UrlValidator(schemes, 0);
       UrlValidator urlVal = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES); 
       StringBuilder tUrl = new StringBuilder();
       
       for(int i = 0; i < totalRuns; i++)
       {
    	   int result = 0;
       //https://stackoverflow.com/questions/35488619/how-to-get-a-random-number-in-a-range-using-math-random
       int schemeIdx = (int)(Math.random() * schemes.length);
       int authIdx = (int)(Math.random() * auth.length);
       int portIdx = (int)(Math.random() * port.length);
       int pathIdx = (int)(Math.random() * path.length);
       int queryIdx = (int)(Math.random() * query.length);
       

       tUrl.append(schemes[schemeIdx]);
       tUrl.append(auth[authIdx]);
       tUrl.append(port[portIdx]);
       tUrl.append(path[pathIdx]);
       tUrl.append(query[queryIdx]);
       
       
       //https://stackoverflow.com/questions/1128723/how-can-i-test-if-an-array-contains-a-certain-value
    	   if(Arrays.asList(badSchemes).contains(schemes[schemeIdx]) || 
    			   Arrays.asList(badAuth).contains(auth[authIdx]) ||
    			   Arrays.asList(badPort).contains(port[portIdx]) ||
    			   Arrays.asList(badPath).contains(path[pathIdx]) ||
    			   Arrays.asList(badQuery).contains(query[queryIdx])) {
    		   result = -1;
    	   }
	   boolean expectedResult = true;
	   String tString = tUrl.toString();
	   boolean actualResult = urlVal.isValid(tString);
	   if(result == -1)
		   expectedResult = false; 
	   
	   System.out.println("Url Under Test: " + tString);
	   System.out.println("Expected: " + expectedResult + " | " + "Actual: " + actualResult);
	   
	   if(expectedResult != actualResult)
		   testFails++;
	   
	   tUrl.delete(0, tUrl.length());
	   result = 0;
       }
	   System.out.println("Test Failed: " + testFails + " out of " + totalRuns + " Runs");
             
	         
   }
   
}
