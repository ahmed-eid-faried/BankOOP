#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h" 
class clsUpdateRateScreen :protected clsScreen {
private:

 

public:
	static void UpdateRate() {
		_DrawScreenHeader("Update Rate Currency");
		string Country = clsCurrency::ReadCountryEixsted("\n\t\t\t\tPlease enter Country? ");
		clsCurrency Currency = clsCurrency::Find(Country);
		Currency.Print();
 		float Rate = clsUtil::ReadDoubleNumber("\t\t\t\tENTER Rate Currency: ");
		Currency.ChangeRate(Rate);
		Currency.Save();
		Currency.Print();

	}
};