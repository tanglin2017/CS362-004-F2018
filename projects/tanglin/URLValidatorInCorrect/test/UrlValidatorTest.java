
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
    @Test
    public void manualTest1() {

        String[] schemes = { "http", "https" };
        UrlValidator urlValidator = new UrlValidator(schemes);

        assertTrue(urlValidator.isValid("https://www.google.com/path.htmlQuery"));
        assertTrue(urlValidator.isValid("http://www.google.com"));

    }

    @Test
    public void manualTest2() {

        UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

        // valid scheme- expected: pass actual: pass
        assertTrue(urlValidator.isValid("http://www.swappa.com/path.htmlQuery#Fragment"));

        // valid scheme- expected: pass actual: fails BUG
        assertTrue(urlValidator.isValid("h://www.swappa.com/path.htmlQuery#Fragment"));

        // invalid scheme- expected: fail actual: fail
        assertFalse(urlValidator.isValid("://www.swappa.com/path.htmlQuery#Fragment"));

    }

    @Test
    public void manualTest3() {

        UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);

        // valid scheme- expected: pass actual: fail BUG
        assertTrue(urlValidator.isValid("https://www.JLS.com/pathQuery#Fragment"));

        // invalid scheme- expected: fail actual: fail
        assertFalse(urlValidator.isValid("http://www.JLS.com//////////pathQuery#Fragment"));
        assertFalse(urlValidator.isValid("http://www.swappa.compathQuery#Fragment"));

    }

    @Test
    public void manualTest4() {

        UrlValidator urlValidator = new UrlValidator(UrlValidator.NO_FRAGMENTS);

        // valid scheme- expected: pass actual: fail BUG
        assertTrue(urlValidator.isValid("http://www.swappa.com"));

        // invalid scheme- expected: fail actual: fail
        assertFalse(urlValidator.isValid("http://www.swappa.com/path.htmlQuery#Fragment"));

    }

    @Test
    public void manualTest5() {

        UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);

        assertTrue(urlValidator.isValid("http://localhost/"));

        assertTrue(urlValidator.isValid("https://swappa/path.html"));

    }


   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	  
	  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("FIRST PARTITION SCHEME TEST USING WWW.GOOGLE.COM");
		   String google = new String("www.google.com");
		   String urlToBeTested="http://"+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   assertTrue(urlVal.isValid(urlToBeTested));
		   
		   urlToBeTested="http:/"+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   //assertTrue(urlVal.isValid(urlToBeTested)==false);
		   
		   urlToBeTested="http:"+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   assertTrue(urlVal.isValid(urlToBeTested)==false);
		   
		   urlToBeTested="http/"+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   assertTrue(urlVal.isValid(urlToBeTested)==false);
		   
		   urlToBeTested="://"+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   //assertTrue(urlVal.isValid(urlToBeTested)==false);
		   
		   urlToBeTested=""+google;
		   System.out.println(urlToBeTested);
		   System.out.println(urlVal.isValid(urlToBeTested));
		   //assertTrue(urlVal.isValid(urlToBeTested));
		   
		   //urlToBeTested="ftp://"+google;
		   //System.out.println(urlToBeTested);
		   //System.out.println(urlVal.isValid(urlToBeTested));
		   //assertTrue(urlVal.isValid(urlToBeTested));
 

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	
		 UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		System.out.println("SECOND PARTITION AUTHORITY TEST USING HTTP://");
	   	   String urlScheme= new String ("http://");
		   String urlToBeTested1=urlScheme+"0.0.0.0";
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		   assertTrue(urlVal.isValid(urlToBeTested1));
		   
		   urlToBeTested1=urlScheme+"255.255.255.255";
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		   assertTrue(urlVal.isValid(urlToBeTested1));
		   
		   urlToBeTested1=urlScheme+"255.255.255.256";
		   System.out.println(urlToBeTested1);		   		   
		   System.out.println(urlVal.isValid(urlToBeTested1));
		 //assertTrue(urlVal.isValid(urlToBeTested1)==false);
		   
		   urlToBeTested1=urlScheme+"1.2.3.4";
		   System.out.println(urlToBeTested1);		   
		   System.out.println(urlVal.isValid(urlToBeTested1));
		 //assertTrue(urlVal.isValid(urlToBeTested1)==false);
		   
		   urlToBeTested1=urlScheme+"1.2.3.4.";
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		 //assertTrue(urlVal.isValid(urlToBeTested1)==false);
		   
		   urlToBeTested1=urlScheme+"google.au";
		   assertTrue(urlVal.isValid(urlToBeTested1));		   
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		   assertTrue(urlVal.isValid(urlToBeTested1));
		   
		   urlToBeTested1=urlScheme+"google.a";		   
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		 //assertTrue(urlVal.isValid(urlToBeTested1)==false);
		   
		   urlToBeTested1=urlScheme+"google";
		   System.out.println(urlToBeTested1);
		   System.out.println(urlVal.isValid(urlToBeTested1));
		 //assertTrue(urlVal.isValid(urlToBeTested1)==false);

   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
   	  System.out.println("Performing programming based unit testing...");

	   //set up URL string components and their expected boolean value from individual functions
	   System.out.println("Testing UrlValidator function:");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES );

	   String scheme[] = {"3ht://", "http:/", "http:", "http/","://", "", "http://"}; //7 total for testing 
	   boolean scheme2[] = {false, false, false, false, false, true,true};
	   
	   String auth[] = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "256.256.256.256",
			   "255.com", "1.2.3.4.5","1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a"}; //12 total for testing 
	   boolean auth2[] = {true, true, true, true, true, false, true, false, false, false, false, false};

	   String port[] = {":80", ":65535", ":0", "",":-1", ":65636", ":65a"}; //7 total for testing 
	   boolean port2[] = {true, true, true, true, false, false, false};
	   
	   String path[] = {"/test1", "/t123","/$23","/..","/../","/test1/","","/test1/file", //10 total for testing 
			   "/..//file","/test1//file"};
	   boolean path2[] = {true, true, true, false, false, true, true, true, false, false};
	   
	   String query[] = {"?action=view","?action=edit&mode=up", ""}; //3 total for testing
	   boolean query2[] = {true, true, true};
	      
	   //seed random number
	   long randomseed = 10;//System.currentTimeMillis();
	   Random random = new Random(randomseed);
	   
	   int pass = 0;
	   int fail = 0;
	   
	for(int i=0; i<10000; i++)
	{
		  String testURL = ""; //this will hold our concatenated test URL
		  int randomNum; // to store our random number
		  boolean isValid = true; //assumed true until false
		
	   /********************Build the string*****************************/
	   randomNum = (int)(Math.random()*8-1); //random number from 0-6 because 7 total  
	   testURL += scheme[randomNum];
	   //System.out.println(testURL);
	   if (scheme2[randomNum] == false)
		   isValid=false;

	   randomNum = (int)(Math.random()*13-1); //random number from 0-11 because 12 total
	   testURL += auth[randomNum];
	   //System.out.println(testURL);
	   if (auth2[randomNum] == false)
		   isValid=false;
	   
	   randomNum = (int)(Math.random()*8-1); //random number from 0-6 because 7 total    
	   testURL += port[randomNum];
	   //System.out.println(testURL);
	   if (port2[randomNum] == false)
		   isValid=false;
	   
	   randomNum = (int)(Math.random()*11-1); //random number from 0-9 because 10 total
	   testURL += path[randomNum];
	   //System.out.println(testURL);
	   if (path2[randomNum] == false)
		   isValid=false;
	   
	   randomNum = (int)(Math.random()*4-1); //random number from 0-2 because 3 total
	   testURL += query[randomNum];
	   //System.out.println(testURL);
	   if (query2[randomNum] == false)
		   isValid=false;
	   
		/******************Test the string*****************************/  
	   
	   try 
	   {
		   if (urlVal.isValid(testURL) == isValid)
		   {
			   pass++;
		   }
		   else
		   {
			   fail++;
		   }
	   }
	   catch(Exception e)
	   {
		    System.out.println("ERROR"); 
	        e.printStackTrace();
            System.out.println("Caused exception: " + testURL);
	   }
	}
	
	System.out.println("Passed cases: " + pass);
	System.out.println("Failed cases: " + fail);
	System.out.println("Programming based unit testing complete.");


   }
   


}