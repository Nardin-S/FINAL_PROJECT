

#include "ADC.h"

void ADC_InIT(void)
{

   switch ( ADC_VOLTAGE_REFERENCE)
   {
	case ADC_VREF_AVCC :
		 Set_bit(ADMUX ,6);
         clr_bit(ADMUX,7) ;
          break;

	case ADC_VREF_AVREF :
		 clr_bit(ADMUX,6);
		 clr_bit(ADMUX,7);
		 break;

	case ADC_VREF_INTERNAL :   // 2.56 V
		 Set_bit(ADMUX,6);
		 Set_bit(ADMUX,7);
		 break;

	default :
		 break;
	}


   switch (ADC_CHANNEL )
   {
   case ADC_CHANNEL_0 :
          // clr_bit(ADMUX,0);
          break;

	case  ADC_CHANNEL_1  :
		 Set_bit(ADMUX,0);
		 break;

	case  ADC_CHANNEL_2  :
		 Set_bit(ADMUX,1);
		 break;

	case  ADC_CHANNEL_3  :
		 Set_bit(ADMUX,0);
		 Set_bit(ADMUX,0);
		 break;

	case  ADC_CHANNEL_4  :
		 Set_bit(ADMUX,2);
		 break;

	case  ADC_CHANNEL_5  :
		 Set_bit(ADMUX,0);
		 Set_bit(ADMUX,2);
		 break;

	case  ADC_CHANNEL_6  :
		 Set_bit(ADMUX,1);
		 Set_bit(ADMUX,2);
		 break;

	case  ADC_CHANNEL_7  :
		 Set_bit(ADMUX,0);
		 Set_bit(ADMUX,1);
		 Set_bit(ADMUX,2);
		 break;

	default:
		 break;
	}


   switch (ADC_ADJUSTMENT)
   {
   case ADC_RIGHT_ADJUST :
     clr_bit(ADMUX,5);
     break;

   case ADC_LEFT_ADJUST :
      Set_bit(ADMUX,5);
      break;
   }


#if   ADC_CONVERSION_TRIGGER   ==  ADC_AUTO_TRIGGER

     Set_bit(ADCSRA,5);

#endif

#if    ADC_RESACLER    ==     ADC_PRESC_128

     Set_bit(ADCSRA,0);
     Set_bit(ADCSRA,1);
     Set_bit(ADCSRA,2);

#endif
#if     ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_DISABLE

     clr_bit(ADCSRA,3);

#endif

  //ENABLE ADC
     Set_bit(ADCSRA,7);



}




void ADC_Read (Uint16 * value)
{
	Uint16 Digital_Value = 0 ;

	Set_bit(ADCSRA,6);

#if   ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_DISABLE

	while(!get_bit(ADCSRA,4));

	Digital_Value = ADC_adjust;

	*value = ((Digital_Value * 500) / 1024 );

#endif
	//return (*value);

}
