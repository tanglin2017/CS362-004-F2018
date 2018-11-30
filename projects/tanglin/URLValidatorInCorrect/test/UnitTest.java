import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class UnitTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void test() {
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
		//   assertTrue(urlVal.isValid(urlToBeTested)==false);
		   
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

}
