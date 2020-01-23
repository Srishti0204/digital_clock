#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#define lcd PORTD
#include<library/lcd.h>
void lcd_string(unsigned char *str)
{     int i=0;
      while(str[i]!='\0')
	  {      lcd_data(str[i]);
	         i++;
      }
}
unsigned char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
void main()
{     DDRD=0xFF;
      lcd_ini();
	  lcd_string("  DIGITAL CLOCK");
	  lcd_command(0xc5);
	  for(int i=0;i<=2;i++)
	    for(int j=0;j<=9;j++)
	      for(int k=0;k<6;k++)
	        for(int l=0;l<=9;l++)
		       for(int m=0;m<=5;m++)
			      for(int n=0;n<=9;n++)
				  {  if((i==2)&&(j==4))
				     {    lcd_command(0xc5);
					      lcd_data('0');
						  lcd_command(0xc6);
						  lcd_data('0');
						  lcd_command(0xc8);
						  lcd_data('0');
						  lcd_command(0xc9);
						  lcd_data('0');
						  lcd_command(0xcB);
						  lcd_data('0');
						  lcd_command(0xcC);
						  lcd_data('0');
						  return;
                     }
				    lcd_command(0xc5);				    
					lcd_data(arr[i]);
					lcd_command(0xc6);
					lcd_data(arr[j]);
					lcd_data(':');
					lcd_data(arr[k]);
					lcd_data(arr[l]);
					lcd_data(':');
					lcd_data(arr[m]);
					lcd_data(arr[n]);
					_delay_ms(1000);
                  }
}




		   
     
	



 
