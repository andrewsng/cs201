//Luke Underwood
//Created 10/28/19
//Menus.cpp
//Contains menu functions for
//CS201 calculator group project application

#include"Header.h"

void trigMenu(const Settings& set)
{
	int menuchoice = 0;
	double num;

	while (menuchoice != 13)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1.  Sine" << std::endl
			<< "\t 2.  Cosine" << std::endl
			<< "\t 3.  Tangent" << std::endl
			<< "\t 4.  Secant" << std::endl
			<< "\t 5.  Cosecant" << std::endl
			<< "\t 6.  Cotangent" << std::endl
			<< "\t 7.  Arcsine" << std::endl
			<< "\t 8.  Arccosine" << std::endl
			<< "\t 9.  Arctangent" << std::endl
			<< "\t 10. Arcsecant" << std::endl
			<< "\t 11. Arccosecant" << std::endl
			<< "\t 12. Arccotangent" << std::endl
			<< "\t 13. Exit" << std::endl;

		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				if (getDouble(num))
				{
					std::cout << std::endl << "sin(" << num << ") = "
						<< sin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 2:
				if (getDouble(num))
				{
					std::cout << std::endl << "cos(" << num << ") = "
						<< cos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 3:
				if (getDouble(num))
				{
					std::cout << std::endl << "tan(" << num << ") = "
						<< tan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 4:
				if (getDouble(num))
				{
					std::cout << std::endl << "sec(" << num << ") = "
						<< 1 / cos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 5:
				if (getDouble(num))
				{
					std::cout << std::endl << "csc(" << num << ") = "
						<< 1 / sin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 6:
				if (getDouble(num))
				{
					std::cout << std::endl << "cot(" << num << ") = "
						<< 1 / tan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 7:
				if (getDouble(num))
				{
					std::cout << std::endl << "asin(" << num << ") = "
						<< asin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 8:
				if (getDouble(num))
				{
					std::cout << std::endl << "acos(" << num << ") = "
						<< acos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 9:
				if (getDouble(num))
				{
					std::cout << std::endl << "atan(" << num << ") = "
						<< atan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 10:
				if (getDouble(num))
				{
					std::cout << std::endl << "asec(" << num << ") = "
						<< 1 / acos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 11:
				if (getDouble(num))
				{
					std::cout << std::endl << "acsc(" << num << ") = "
						<< 1 / asin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 12:
				if (getDouble(num))
				{
					std::cout << std::endl << "acot(" << num << ") = "
						<< 1 / atan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 13:
				break;
			default:
				std::cout << "Please enter one of the options." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
		}
	}
}


void optionMenu(Settings& set)
{
	int menuchoice = 0;
	int num;
	std::string choice;

	while (menuchoice != 4)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Radians/Degrees" << std::endl
			<< "\t 2. Floating point ammount" << std::endl
			<< "\t 3. Normal/Scientific" << std::endl
			<< "\t 4. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				std::cout << "Please type \"R\" for radians, or "
					<< "\"D\" for degrees: ";
				getline(std::cin, choice);
				if (choice == "R" || choice == "r")
				{
					set.radians = true;
					std::cout << "You are now in radians mode" << std::endl;
				}
				else if (choice == "D" || choice == "d")
				{
					set.radians = false;
					std::cout << "You are now in degrees mode" << std::endl;
				}
				else
				{
					std::cout << "Unrecognized input. Please try again."
						<< std::endl;
				}
				break;
			case 2:
				std::cout << "Please enter the number of digits you would"
					<< " like to have after the decimal: " << std::endl;
				if (getInt(num))
				{
					std::cout << std::fixed << std::setprecision(num);
					set.floatnum = num;
					std::cout << "There will now be " << num
						<< " decimal places" << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer.";
				}
				break;
			case 3:
				std::cout << "Please type \"N\" for normal, or "
					<< "\"S\" for scientific: ";
				getline(std::cin, choice);
				if (choice == "N" || choice == "n")
				{
					set.scientific = false;
					std::cout << std::fixed << "You are now in normal mode" << std::endl;
				}
				else if (choice == "S" || choice == "s")
				{
					set.scientific = true;
					std::cout << std::scientific << "You are now in scientific mode" << std::endl;
				}
				else
				{
					std::cout << "Unrecognized input. Please try again."
						<< std::endl;
				}
				break;
			case 4:
				break;
			default:
				std::cout << "Please enter one of the numbers listed."
					<< std::endl;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}
	}

}

void combinatoricsMenu() {
    int menuchoice = 0;
    int num3;
    int num4;
    
    // Function for paramaters will probably use getint

    while (menuchoice != 10)
    {
        std::cout << std::endl
            << "Please select one of the following options:" << std::endl
            << "\t 1.  Permuatation" << std::endl
            << "\t 2.  Combination" << std::endl
            << "\t 3.  K-list" << std::endl
            << "\t 4.  Multiset" << std::endl
            << "\t 5.  Stirling-Number" << std::endl
            << "\t 6.  Sum Stirling-Number" << std::endl
            << "\t 7.  Bell Number" << std::endl
            << "\t 8.  Partitions of an Integer" << std::endl
            << "\t 9.  Sum Partitions of an Integer" << std::endl
            << "\t 10. Exit" << std::endl;

        if (getInt(menuchoice))
        {
            switch (menuchoice)
            {
            case 1:
                std::cout << "Please enter an integer." << std::endl;
                if (getInt(num3)) {
                    fact(num3);
                }
                else
                {
                    std::cout << "Please enter an integer." << std::endl;
                }

                //permutation paramaters int
                break;

            case 2:
                std::cout << "Please enter 2 integers" << std::endl;
                    if (getInt(num3) && getInt(num4)){
                        combination(num3, num4, 1);
                    }
                else
                {
                    std::cout << "Please enter 2 integers." << std::endl;
                }
                break;

            case 3:
                    
                    std::cout << "Please enter an 2 integers." << std::endl;
                    if (getInt(num3)&&getInt(num4)){
                        klist(num3,num4);
                    }
                    else
                                {
                                    std::cout << "Please enter an integer." << std::endl;
                                }
                    
                // K list paramaters 2 ints
                break;

            case 4:
                    
                    std::cout << "Please enter 2 integers" << std::endl;
                    if (getInt(num3) && getInt(num4))
                    {
                             combination(num3+num4-1, num4, 0);
                    }
                    else
                    {
                        std::cout << "Please enter 2 integers." << std::endl;
                    }
                    
                // Multiset paramaters 2 ints
                break;
            case 5:
                    std::cout << "Please enter 2 integers" << std::endl;
                    if (getInt(num3) && getInt(num4)){
                        stirling(num3, num4);
                    }
                    else
                    {
                    std::cout << "Please enter 2 integers." << std::endl;
                    }
                    break;
                    
                //stirling number paramaters 2 ints
                break;
            case 6:
                //sum stirling number paramaters 2 ints
                break;
            case 7:
                // bell number paramater 1 int
                break;
            case 8:
                // partitions of an integer paramaters 2 ints
                break;
            case 9:
                // sum partitions of an integer paramates 2 ints
                break;
            case 10:
                break;
            default:
                std::cout << "Please enter one of the options." << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Please enter an integer." << std::endl;
        }
    }
}








void vectorMenu(const Settings& set)
{
	int menuchoice = 0;
	int vecNum = 0;
	int vecPlaces = 0;
	std::vector<std::vector<double>> vecVec;

	while (menuchoice != 8)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Find the Magnitude" << std::endl
			<< "\t 2. Add Vectors" << std::endl
			<< "\t 3. Scalar Multiplication" << std::endl
			<< "\t 4. Dot Product" << std::endl
			<< "\t 5. Cross Product" << std::endl
			<< "\t 6. Scalar Triple Product" << std::endl
			<< "\t 7. Normalize the Vector" << std::endl
			<< "\t 8. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{

			//Magnitude
			case 1:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					std::cout << std::endl << "|| ";
					printVector(vecVec[0]);
					std::cout << " ||";

					double magnitude = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						magnitude += pow(vecVec[0][i], 2);
					}
					magnitude = pow(magnitude, 0.5);
					std::cout << " = " << magnitude << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Addition
			case 2:
				std::cout << "How many vectors are you adding?\n";
				if (getInt(vecNum))
				{
					vecVec = makeMatrix(vecNum);
					std::cout << "How many elements are in each vector?\n";
					if (getInt(vecPlaces))
					{
						vecVec = populateVectors(vecNum, vecPlaces);

						std::cout << std::endl;
						for (auto n : vecVec)
						{
							printVector(n);
							if (n != vecVec.back())
							{
								std::cout << " + ";
							}
						}

						std::vector<double> addAns(vecPlaces, 0);
						for (auto n : vecVec)
						{
							for (size_t i = 0; i < n.size(); i++)
							{
								addAns[i] += n[i];
							}
						}
						std::cout << " = ";
						printVector(addAns);
						std::cout << std::endl;
					}
					else
					{
						std::cout << "Please enter an integer.\n";
					}
				}
				else
				{
					std::cout << "Please enter an integer.\n";
				}
				break;

			//Scalar Multiplication
			case 3:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					std::cout << "What are you multiplying by?";
					std::cout << std::endl;
					double scalar;
					if (!getDouble(scalar))
					{
						std::cout << "Bad input. Please enter a number\n";
						while (!getDouble(scalar))
						{
							std::cout << "Bad input. Please enter a number\n";
						}
					}
					std::cout << std::endl << scalar << " * ";
					printVector(vecVec[0]);

					std::vector<double> scaled(vecPlaces, 0);
					for (int i = 0; i < vecPlaces; i++)
					{
						scaled[i] = vecVec[0][i] * scalar;
					}
					std::cout << " = ";
					printVector(scaled);
					std::cout << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Dot Product
			case 4:
				vecNum = 2;
				std::cout << "How many elements are in each vector?" 
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					std::cout << std::endl;
					printVector(vecVec[0]);
					std::cout << " DOT ";
					printVector(vecVec[1]);

					double dotAns = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						dotAns += vecVec[0][i] * vecVec[1][i];
					}
					std::cout << " = " << dotAns << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Cross Product
			case 5:
			{
				vecNum = 2;
				vecPlaces = 3;
				std::cout << "Only the crossing of two, three element vectors "
					<< "is supported." << std::endl;

				vecVec = populateVectors(vecNum, vecPlaces);

				std::vector<double> crossAns(vecPlaces, 0);
				crossAns[0] = vecVec[0][1] * vecVec[1][2] - vecVec[1][1]
					* vecVec[0][2];
				crossAns[1] = (vecVec[0][0] * vecVec[1][2] - vecVec[1][0]
					* vecVec[0][2]) * -1;
				crossAns[2] = vecVec[0][0] * vecVec[1][1] - vecVec[1][0]
					* vecVec[0][1];

				std::cout << std::endl;
				printVector(vecVec[0]);
				std::cout << " X ";
				printVector(vecVec[1]);
				std::cout << " = ";
				printVector(crossAns);
				std::cout << std::endl;

				break;
			}

			//Triple Product
			case 6:
			{
				vecNum = 3;
				vecPlaces = 3;
				std::cout << "The first two vectors will be crossed, and"
					<< " the result will be dotted with the third vector."
					<< std::endl;

				vecVec = populateVectors(vecNum, vecPlaces);

				std::cout << std::endl;
				std::cout << "( ";
				printVector(vecVec[0]);
				std::cout << " X ";
				printVector(vecVec[1]);
				std::cout << " ) DOT ";
				printVector(vecVec[2]);

				std::vector<double> crossAns(vecPlaces, 0);
				crossAns[0] = vecVec[0][1] * vecVec[1][2] - vecVec[1][1] 
					* vecVec[0][2];
				crossAns[1] = (vecVec[0][0] * vecVec[1][2] - vecVec[1][0] 
					* vecVec[0][2]) * -1;
				crossAns[2] = vecVec[0][0] * vecVec[1][1] - vecVec[1][0] 
					* vecVec[0][1];

				double dotAns = 0;
				for (int i = 0; i < vecPlaces; i++)
				{
					dotAns += vecVec[2][i] * crossAns[i];
				}
				std::cout << " = " << std::to_string(dotAns) << std::endl;
				break;
			}

			//Normalize
			case 7:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					double scalar = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						scalar += pow(vecVec[0][i], 2);
					}
					scalar = pow(scalar, 0.5);

					std::cout << std::endl;
					printVector(vecVec[0]);
					std::cout << " / " << scalar;

					std::vector<double> scaled(vecPlaces, 0);
					for (int i = 0; i < vecPlaces; i++)
					{
						scaled[i] = vecVec[0][i] / scalar;
					}
					std::cout << " = ";
					printVector(scaled);
					std::cout << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;
			case 8:
				break;
			default:
				std::cout << "Please enter one of the numbers listed."
					<< std::endl;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}
	}

}


void polynomialMenu(const Settings& set)
{
	int menuchoice = 0;
	int magnitude = 0;
	std::vector<double> zeros;

	while (menuchoice != 4)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Find the Zeros" << std::endl
			<< "\t 2. Solution of Two Linear Equations" << std::endl
			<< "\t 3. Binomial Expansion" << std::endl
			<< "\t 4. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			//Zeros
			case 1:
			{
				std::cout << "What is the highest exponent in your polynomial?"
					<< std::endl;
				if (getInt(magnitude))
				{
					std::vector<double> coefficients(magnitude + 1);

					for (int i = 0; i <= magnitude; i++)
					{
						std::cout << "What is the coefficient of x ^ "
							<< std::setprecision(0) << i
							<< std::setprecision(set.floatnum) << "?\n";
						while (!getDouble(coefficients[i]))
						{
							std::cout << "Please enter a number.\n";
						}
					}
					std::cout << "Calculating. This can take a long time "
						<< "depending on your function." << std::endl;
					while (coefficients[0] == 0)
					{
						coefficients.erase(coefficients.begin());
						magnitude--;
						if (zeros.size() == 0)
						{
							zeros.push_back(0);
						}
					}

					int positives = 0;
					for (int i = 1; i <= magnitude; i++)
					{
						if ((coefficients[i] < 0 && coefficients[i - 1] >= 0)||
							(coefficients[i] >= 0 && coefficients[i - 1] < 0))
						{
							positives++;
						}
					}

					int negatives = 0;
					std::vector<double> negativesTest = coefficients;

					for (int i = 1; i <= magnitude; i += 2)
					{
						negativesTest[i] *= -1;
					}

					for (int i = 1; i <= magnitude; i++)
					{
						if ((negativesTest[i] < 0 && negativesTest[i - 1] >= 0)
							|| (negativesTest[i] >= 0 
								&& negativesTest[i - 1] < 0))
						{
							negatives++;
						}
					}

					mpf_set_default_prec(1024);

					mpf_t x;
					mpf_t h;
					mpf_t m1;
					mpf_t m2;
					mpf_t fofX;
					mpf_t fXplusH;
					mpf_t fXminusH;
					mpf_t coefficient;
					mpf_inits(x, h, m1, m2, fofX,
						fXplusH, fXminusH, coefficient, NULL);
					mpf_set_d(h, 0.00000000000000000000000000001);
					mpf_set_d(fofX, 1);

					int posZerosFound = 0;
					int negZerosFound = 0;
					int iOut = 0;
					int iIn = 0;

					while ((posZerosFound < positives
						|| negZerosFound < negatives)
						&& iOut < magnitude * 2)
					{

						while ((mpf_get_d(fofX) > mpf_get_d(h)
							|| mpf_get_d(fofX) < -1 * mpf_get_d(h))
							&& iIn < 100)
						{
							mpf_set_d(fofX, 0);
							mpf_set_d(fXplusH, 0);
							mpf_set_d(fXminusH, 0);

							for (int i = 0; i <= magnitude; i++)
							{
								mpf_set_d(coefficient, coefficients[i]);
								mpf_t term;
								mpf_init2(term, 2048);
								mpf_pow_ui(term, x, i);
								mpf_mul(term, term, coefficient);
								mpf_add(fofX, fofX, term);

								mpf_add(term, x, h);
								mpf_pow_ui(term, term, i);
								mpf_mul(term, term, coefficient);
								mpf_add(fXplusH, fXplusH, term);

								mpf_sub(term, x, h);
								mpf_pow_ui(term, term, i);
								mpf_mul(term, term, coefficient);
								mpf_add(fXminusH, fXminusH, term);
							}

							if (mpf_get_d(fofX) < mpf_get_d(h)
								&& mpf_get_d(fofX) > -1 * mpf_get_d(h))
							{
								bool exist = false;
								for (auto n : zeros)
								{
									if (n == mpf_get_d(x))
									{
										exist = true;
										break;
									}
								}
								if (!exist)
								{
									zeros.push_back(mpf_get_d(x));
									if (mpf_get_d(x) > 0)
									{
										posZerosFound++;
									}
									else if (mpf_get_d(x) < 0)
									{
										negZerosFound++;
									}
								}
								continue;
							}

							mpf_sub(m1, fXplusH, fofX);
							mpf_div(m1, m1, h);
							mpf_sub(m2, fofX, fXminusH);
							mpf_div(m2, m2, h);

							mpf_add(m1, m1, m2);
							mpf_div_ui(m1, m1, 2);

							if (mpf_get_d(m1) < mpf_get_d(h)
								&& mpf_get_d(m1) > -1 * mpf_get_d(h))
							{
								mpf_add_ui(x, x, 1);
							}
							else
							{
								mpf_div(fofX, fofX, m1);
								mpf_sub(x, x, fofX);
							}

							iIn++;
						}

						switch (iOut % 4)
						{
						case 0:
							mpf_set_d(x, pow((iOut + 1), 0.33));
							break;
						case 1:
							mpf_set_d(x, -pow((iOut + 1), 0.33));
							break;
						case 2:
							mpf_set_d(x, pow(iOut, 2) + 1);
							break;
						case 3:
							mpf_set_d(x, -pow(iOut, 2) + 1);
							break;
						}
						mpf_set_d(fofX, 1);
						iIn = 0;
						iOut++;

					}

					std::cout << std::endl << zeros.size() << " zeros found. "
						<< "They are: ";

					for (auto n : zeros)
					{
						std::cout << n << "  ";
					}
					std::cout << std::endl;

					mpf_clears(x, h, m1, m2, fofX,
						fXplusH, fXminusH, coefficient, NULL);
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				zeros.clear();
				break;
			}

			//Systems
			case 2:
			{
				std::pair<double, double> line1;
				std::pair<double, double> line2;

				std::cout << "Enter the slope of the first line\n";
				while (!getDouble(line1.first))
				{
					std::cout << "Please enter a number.\n";
				}
				std::cout << "Enter the constant added to the first line\n";
				while (!getDouble(line1.second))
				{
					std::cout << "Please enter a number.\n";
				}
				std::cout << "Enter the slope of the second line\n";
				while (!getDouble(line2.first))
				{
					std::cout << "Please enter a number.\n";
				}
				std::cout << "Enter the constant added to the second line\n";
				while (!getDouble(line2.second))
				{
					std::cout << "Please enter a number.\n";
				}

				std::cout << std::endl << "These lines intersect at (" 
					<< (line1.second - line2.second) / 
					(line2.first - line1.first) << " , " 
					<< line1.first* (line1.second - line2.second) / 
					(line2.first - line1.first) + line1.second << ")" 
					<< std::endl;


				break;
			}

			//Expansion
			case 3:
			{
				std::string termA;
				std::pair<double, char> pairA = { 0, NULL };

				std::cout << "Enter the first term of your binomial: ";
				std::getline(std::cin, termA);
				std::istringstream instream(termA);
				instream >> pairA.first;
				if (!instream)
				{
					std::cout << "Invalid input.\n";
					break;
				}
				if ((termA.back() > 'A' && termA.back() < 'Z')
					|| (termA.back() > 'a' && termA.back() < 'z'))
				{
					pairA.second = termA.back();
				}

				std::string termB;
				std::pair<double, char> pairB = { 0, NULL };

				std::cout << "Enter the second term of your binomial: ";
				std::getline(std::cin, termB);
				std::istringstream instream2(termB);
				instream2 >> pairB.first;
				if (!instream2)
				{
					std::cout << "Invalid input.\n";
					break;
				}
				if ((termB.back() > 'A' && termB.back() < 'Z')
					|| (termB.back() > 'a' && termB.back() < 'z'))
				{
					pairB.second = termB.back();
				}

				int exp;
				std::cout << "Enter the power is is being raised to: ";
				while(!getInt(exp))
				{
					std::cout << "Invalid input.\n";
				}

				std::vector<std::vector<int>> triangle;
				for (int i = 0; i <= exp; i++)
				{
					std::vector<int> temp;
					for (int j = 0; j <= i; j++)
					{
						
						if (j == i || j == 0)
						{
							temp.push_back(1);
						}
						else
						{
							temp.push_back(triangle[i - 1][j - 1] + 
								triangle[i - 1][j]);
						}
					}
					triangle.push_back(temp);
				}

				std::cout << std::endl;
				for (int i = 0; i <= exp; i++)
				{
					std::cout << triangle[exp][i] * pow(pairA.first, exp - i)
						* pow(pairB.first, i);

					if ((pairA.second != NULL && exp != i) || 
						(pairB.second != NULL && i != 0))
					{
						std::cout << "(";
					}

					if (exp != i && pairA.second != NULL)
					{
						std::cout << pairA.second << " ^ " << exp - i;
					}

					if (exp != i && i != 0 && 
						pairA.second != NULL && pairB.second != NULL)
					{
						std::cout << " * ";
					}

					if (i != 0 && pairB.second != NULL)
					{
						std::cout << pairB.second << " ^ " << i;
					}
					
					if ((pairA.second != NULL && exp != i) || 
						(pairB.second != NULL && i != 0))
					{
						std::cout << ")";
					}

					if (i < exp)
					{
						std::cout << " + ";
					}
				}
				std::cout << std::endl;
				break;
			}

			//Exit
			case 4:
				break;
			default:
				std::cout << "Please enter one of the numbers listed."
					<< std::endl;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}
	}

}


//(TEMP) Andrew's tokenizer stuff

void derivTest()
{
	long double lower;
	long double upper;
	std::string origFunc = "x^2";

	double point = 1.00000000000000000000000000000000000000;
	mpf_t x;
	mpf_t xP;
	mpf_t xM;
	mpf_t xD;
	mpf_set_d(x, point);
	mpf_set_d(xP, point + sqrt(DBL_EPSILON));
	mpf_set_d(xM, point - sqrt(DBL_EPSILON));
	mpf_set_d(xD, 2.0 * sqrt(DBL_EPSILON));

	mp_exp_t expptr = 0;
	char* cptrM = 0;
	mpf_get_str(cptrM, &expptr, 10, 0, xM);
	std::string pointM = std::string(cptrM);
	mpf_clear(xM);
	free(cptrM);

	std::cout << pointM << std::endl;

	/*long double pointM = point - sqrt(0.00000000001);
	std::ostringstream ossP;
	ossP << std::fixed << std::setprecision(1000);
	ossP << xM;
	std::string pointS = ossP.str();
	std::cout << std::setprecision(50) << pointS << std::endl;

	long double pointH = point + sqrt(0.00000000001);
	std::ostringstream ossPH;
	ossPH << std::fixed << std::setprecision(1000);
	ossPH << xP;
	std::string pointHS = ossPH.str();
	std::cout << pointHS << std::endl;

	std::ostringstream ossD;
	ossD << std::fixed << std::setprecision(1000);
	ossD << xD;
	std::string pointD = ossD.str();
	std::cout << pointD << std::endl;

	std::string copy1 = origFunc;
	for (size_t i = 0; i < copy1.size(); ++i) {
		if (copy1[i] == 'x') {
			copy1.replace(i, i + 1, pointS);
		}
	}
	std::string copy2 = origFunc;
	for (size_t i = 0; i < copy2.size(); ++i) {
		if (copy2[i] == 'x') {
			copy2.replace(i, i + 1, pointHS);
		}
	}
	
	std::string newFunc = "((" + copy2 + ") - (" + copy1 + ")) / " + pointD;
	std::cout << newFunc;
	std::vector<std::string> tokens;
	makeTokens(tokens, newFunc);
	evaluateTokens(tokens);
	tokens.clear();
	*/
}

void lineBasedMenu()
{
	std::cout << std::endl << "Enter a line to calculate it, or type \"quit\" to go back\n\n";
	std::cout << "Current features:\n";
	std::cout << "(+), (-), (/), (*)\n";
	std::cout << "sin(), cos(), tan(), arcsin(), arccos(), arctan()\n";
	std::cout << "^, ln(), sqrt()" << std::endl;
	std::string str;
	std::vector<std::string> tokens;
	while (true) {
		std::cout << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << std::endl;
		std::getline(std::cin, str);
		if (str.empty()) {
			continue;
		}
		if (str == "quit") {
			break;
		}
		makeTokens(tokens, str);
		evaluateTokens(tokens);
		tokens.clear();
	}
}

void makeTokens(std::vector<std::string>& tokens, std::string& str)
{
	std::string token;
	bool op = 0;
	bool num = 0;
	bool deci = 0;
	bool alph = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (isblank(c)) {
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
			continue;
		}
		if (ispunct(c) && c != '.') {
			if (i == 0) {
				op = 1;
			}
			if (op && c == '-') {
				op = 0;
				num = 1;
				if (!token.empty()) {
					tokens.push_back(token);
				}
				token.clear();
				token.push_back(c);
				continue;
			}
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
			token.push_back(c);
			tokens.push_back(token);
			token.clear();
			if (c != '(' && c != ')') {
				op = 1;
			}
			num = 0;
			alph = 0;
		}
		else if (isdigit(c) || c == '.') {
			op = 0;
			if (!alph) {
				num = 1;
				token.push_back(c);
			}
			else {
				tokens.push_back(token);
				token.clear();
				alph = 0;
				num = 1;
				token.push_back(c);
			}
		}
		else if (isalpha(c)) {
			op = 0;
			if (!num) {
				alph = 1;
				token.push_back(c);
			}
			else {
				tokens.push_back(token);
				token.clear();
				num = 0;
				alph = 1;
				token.push_back(c);
			}
		}
		if (i + 1 == str.size()) {
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
		}
	}
}

void evaluateTokens(std::vector<std::string>& tokens) {
	size_t num = 0;
	std::vector<int> leftParen;
	for (size_t i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "(") {
			leftParen.push_back(i);
			for (size_t j = i + 1; j < tokens.size(); ++j) {
				if (tokens[j] == "(") {
					++num;
					leftParen.push_back(j);
					i = j;
					continue;
				}
				if (tokens[j] == ")") {
					long double result = evalInside(i, j, tokens);
					if (result == LDBL_MAX) {
						std::cout << std::endl << "ERROR" << std::endl;
						return;
					}
					tokens.erase(tokens.begin() + i, tokens.begin() + j + 1);
					tokens.insert(tokens.begin() + i, std::to_string(result));
					if (num > 0) {
						--num;
					}
					else {
						leftParen.clear();
					}
					i = 0;
					break;
				}
			}
		}
	}
	long double r = evalInside(0, tokens.size(), tokens);
	if (r == LDBL_MAX) {
		std::cout << std::endl << "ERROR" << std::endl;
		return;
	}
	std::cout << std::endl << std::setw(15) << r << std::endl;
}

long double evalInside(const size_t& left, const size_t& right, std::vector<std::string>& tokens) {
	std::vector<std::string> op;
	std::vector<long double> numbers;
	for (size_t i = left; i < right; ++i) {
		std::istringstream is(tokens[i]);
		long double num;
		if (is >> num) {
			op.push_back("null");
			numbers.push_back(num);
		}
		else if (tokens[i] != "(" && tokens[i] != ")") {
			op.push_back(tokens[i]);
			numbers.push_back(LDBL_MAX);
		}
	}
	if (numbers.size() == 1) {
		return numbers[0];
	}
	if (left + 1 == right) {
		return LDBL_MAX;
	}
	for (size_t i = 0; i < numbers.size() - 1; ++i) {
		if (numbers[i] != LDBL_MAX && numbers[i + 1] != LDBL_MAX) {
			return LDBL_MAX;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "sin") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = sin(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "cos") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = cos(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "tan") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = tan(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "arcsin") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = asin(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "arccos") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = acos(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "arctan") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = atan(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "ln") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = log(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "sqrt") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = sqrt(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 1);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "^") {
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = pow(numbers[i - 1], numbers[i + 1]);
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 2);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "*") {
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] * numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 2);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "/") {
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] / numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 2);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "+") {
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] + numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 2);
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "-") {
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] - numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
			op.erase(op.begin() + i, op.begin() + i + 2);
			i = 0;
		}
	}
	return numbers[0];
}