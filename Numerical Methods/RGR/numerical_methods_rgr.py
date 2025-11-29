import numpy as np
import scipy
import scipy.special as special
import scipy.integrate as integrate

def integrate_hermite(integrated_funct, nodes_amount) -> float:
    """
    Вычисляет приближённое значение интеграла вида:
    I(integrated_funct(x) * e^(-2x)) от -inf, до +inf.
    :param integrated_funct: Интегрируемая ф-ия - мн-ен степени не выше чем 2 * nodes_amount - 1.
    :param nodes_amount: Количество узлов.
    :return: Приближённое значение вычисленного интеграла.
    """
    x_nodes, weights = special.roots_hermite(nodes_amount)

    integral_approximation = 0.0

    for i in range(nodes_amount):
        xi = x_nodes[i]
        wi = weights[i]

        integral_approximation += wi * integrated_funct(xi)

    return integral_approximation

def function(arg) :
    return 2 * arg**2 + 4 * arg + 3

def function2(arg) :
    return function(arg) * np.exp(-arg**2)

exact = integrate.quad(function2, -np.inf, np.inf)
print(f"Точное значение ф-ии: {exact[0]}.")
for n in [1, 2, 3, 5, 10, 20, 100]:
    approx = integrate_hermite(function, n)
    print(f"При n = {n} имеет приближённое значение интеграла равное {approx}")