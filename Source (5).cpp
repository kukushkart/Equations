#include "Equations.h"

void PrintCounters(size_t count_1, size_t count_2) {
    std::cout << "Number of linear equations is: " << count_1 << "\n";
    std::cout << "Number of quadratic equations is: " << count_2 << "\n";
}

void AreThereAnyEquations(std::vector<Equation*> equations) {
    if (equations.size() == 0) {
        throw std::logic_error("There is no frickin equations in da vector");
    }
}

void PrintEnteredEquations(std::vector<Equation*> equations) {
    std::cout << "Entered equations:\n";
    for (size_t i = 0; i < equations.size(); ++i) {
        equations[i]->Print();
    }
}

void PrintSolutions(std::vector<Equation*> equations) {
    std::cout << "\n" << "Solutions: \n";

    for (const auto& eq : equations) {
        std::cout << "Solution for the equation: ";
        eq->Print();
        eq->Solve();
    }

    std::cout << "\n\n";
}

void PrintEquationsWithNoSolutions(std::vector<Equation*> equations) {
    std::cout << "Equations with no solutions:\n";
    size_t counter = 0;
    for (const auto& eq : equations) {
        if (eq->HasNoSolution()) {
            ++counter;
            eq->Print();
        }
    }
    if (counter == 0) {
        std::cout << "\tThere is no Equations with no solutions\n";
    }

    std::cout << "\n";
}

void PrintNumOfEquationsWithInfSol(std::vector<Equation*> equations) {
    size_t infinite_solutions_count = 0;
    for (const auto& eq : equations) {
        if (eq->HasInfiniteSolutions()) {
            infinite_solutions_count++;
        }
    }
    std::cout << "Number of equations with infinite solutions: " << infinite_solutions_count << "\n";

    std::cout << "\n";
}

void SortEquationsByLeadCoef(std::vector<Equation*> equations) {
    std::sort(equations.begin(), equations.end(), [](Equation* a, Equation* b) {
        return a->GetLeadingCoefficient() < b->GetLeadingCoefficient();
        });
    std::cout << "Sorted equations by leading coefficient:\n";
    for (const auto& eq : equations) {
        eq->Print();
    }

    std::cout << "\n";
}

void PrintQuadEquationsWithNegDisc(std::vector<Equation*> equations) {
    std::cout << "Quadratic equations with negative discriminant:\n";
    for (const auto& eq : equations) {
        if (eq->IsQuadratic() && eq->IsNegativeDiscriminant()) {
            eq->Print();
        }
    }

    std::cout << "\n";
}

void PrintQuadEquationsWithDdownwardParabola(std::vector<Equation*> equations) {
    std::cout << "Quadratic equations with downward parabola:\n";
    size_t num_of_quad_eq = 0;
    for (const auto& eq : equations) {
        if (eq->IsQuadratic() && eq->IsDownwardParabola()) {
            eq->Print();
            ++num_of_quad_eq;
        }
    }
    if (num_of_quad_eq == 0) {
        std::cout << "\tNo equations with downward parabola\n";
    }

    std::cout << "\n";
}

void PrintQuadEquationsThatArePerfectSquares(std::vector<Equation*> equations) {
    std::cout << "Quadratic equations that are perfect squares:\n";
    std::vector<Equation*> perfect_squares;
    size_t num_of_perf_sq = 0;
    for (const auto& eq : equations) {
        if (eq->IsQuadratic() && eq->IsPerfectSquare()) {
            ++num_of_perf_sq;
            perfect_squares.push_back(eq);
        }
    }
    if (num_of_perf_sq == 0) {
        std::cout << "\tNo equations that are perfect square\n";
    }
    else {
        std::sort(perfect_squares.begin(), perfect_squares.end(), [](Equation* a, Equation* b) {
            return a->GetLeadingCoefficient() < b->GetLeadingCoefficient();
            });
        for (const auto& eq : perfect_squares) {
            eq->Print();
        }
    }

    std::cout << "\n";
}

void PrintSortedLinEquationsWithSomeParametr(std::vector<Equation*> equations) {
    std::cout << "Linear equations with b > k, sorted by b in descending order:\n";
    std::vector<Equation*> linear_b_greater_c;
    size_t num_of_lin_eq = 0;
    for (const auto& eq : equations) {
        if (eq->IsLinear() && eq->GetB() > eq->GetC()) {
            linear_b_greater_c.push_back(eq);
            ++num_of_lin_eq;
        }
    }
    if (num_of_lin_eq == 0) {
        std::cout << "No equations with b > k\n";
    }
    else {
        std::sort(linear_b_greater_c.begin(), linear_b_greater_c.end(), [](Equation* a, Equation* b) {
            return a->GetB() > b->GetB();
            });
        for (const auto& eq : linear_b_greater_c) {
            eq->Print();
        }
    }

    std::cout << "\n";
}

void PrintCountOfLinAndQuadEqByDynamicCast(std::vector<Equation*> equations) {
    size_t quad_count{};
    size_t lin_count{};

    for (size_t i = 0; i < equations.size(); ++i) {
        if (dynamic_cast<LinearEquation*>(equations[i]) == nullptr) {
            ++quad_count;
        }
        else {
            ++lin_count;
        }
    }

    PrintCounters(lin_count, quad_count);
    std::cout << "\n";
}

void PrintCountOfLinAndQuadEqByTypeInfo(std::vector<Equation*> equations) {
    size_t quad_count{};
    size_t lin_count{};

    const type_info& ti_1 = typeid(LinearEquation);
    const type_info& ti_2 = typeid(QuadraticEquation);

    for (size_t i = 0; i < equations.size(); ++i) {
        if (ti_1 == typeid(*equations[i])) {
            ++lin_count;
        }
        else {
            ++quad_count;
        }
    }

    PrintCounters(lin_count, quad_count);

    std::cout << "\n";
}

void DeleatingVectorOfEquations(std::vector<Equation*> equations) {
    for (const auto equationsi : equations) {
        delete equationsi;
    }
}

int main() {
    try {
        std::vector<Equation*> equations;

        equations.push_back(new LinearEquation(5, 3));
        equations.push_back(new LinearEquation(0, 0));
        equations.push_back(new QuadraticEquation(2, 4, 1));
        equations.push_back(new LinearEquation(3, 7));
        equations.push_back(new LinearEquation(3, 8));
        equations.push_back(new LinearEquation(9, 1));
        equations.push_back(new QuadraticEquation(-1, 4, -4));
        equations.push_back(new LinearEquation(14, -2));
        equations.push_back(new QuadraticEquation(1, 6, 34242));

        AreThereAnyEquations(equations);

        PrintEnteredEquations(equations);

        PrintSolutions(equations);

        PrintEquationsWithNoSolutions(equations);

        PrintNumOfEquationsWithInfSol(equations);

        SortEquationsByLeadCoef(equations);

        PrintQuadEquationsWithNegDisc(equations);

        PrintQuadEquationsWithDdownwardParabola(equations);

        PrintQuadEquationsThatArePerfectSquares(equations);

        PrintSortedLinEquationsWithSomeParametr(equations);

        PrintCountOfLinAndQuadEqByDynamicCast(equations);

        PrintCountOfLinAndQuadEqByTypeInfo(equations);

        DeleatingVectorOfEquations(equations);

        return 0;
    }
    catch (const std::logic_error& error) {
        std::cerr << error.what() << std::endl;
    }
}