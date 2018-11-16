Title: 03-65-205 Statistics Notes
Author: Benjamin Davidson
Creation Date: September 10, 2017
Source: Introduction to Probability and Statistics -3rd Canadian Edition (Mendenhall, Beaver, Beaver, Ahmed)  

# Table of Contents

 <!--toc max2-->

# Lesson #1
**Inferential statistics**: procedures used to make inferences about population characteristics from information contained in a sample drawn from this population. 

Basic steps of *inferential statistics*

1. specify the questions to be answered and identity the population of interest. 
2. Decide how to select the sample. 
3. Select a sample and analyze the sample information. 
4. Use the information from step three to make an inference about the population
5. Determine the reliability of the inference. 

**Variable**: a characteristic that changes or varies over time and/or for different individuals or objects under consideration

**experimental unit:**  individual or object on which variable is measured

**measurement:** Data value resulting from a variable being measured on an experimental unit

**population:** A set of all the measurements of interest to investigator

**sample:** A smaller subset of the population of interest. 

#Lesson #2 / ch2 - Describing Data w/ Numerical Measures 0925-2017 11:27  

**parameters**: measures that are computed based on the *entire* population data.

**statistics**: measures that are computed from sample data. 

## 2.2 Measures of Centre

### **Arithmetic mean** \\(\bar{x}\\): 

**`x̅` represents *sample* mean.  
`µ` represents mean of a *population***.   

\\[ \sum\limits_{i=1}^n x_i \\]

`∑`: Sum  
`n`: the upper number represents the end of the set  
`x`: measurements (a set)    
`i = 1`: starting index  

- The typical sums in statistica calculations are made of the sum of `n` set of measurements we can use:

\\[\sum x_i \\]

### Formula for sample mean 

\\[ \bar{x} = \frac{\sum x_i}{n}\\]

## Median \\( m \\)

\\[ 0.5(n + 1)\\]

indicates the *position of the median* in an ordered set. If the position of the median ends in `0.5`, then you need to take the average of the two adjacent values.

## Mode

**Mode**: the category that occurs most frequently.  


## Measures of variability

**variability**: the amount the numbers are spread out from the centre. **Measures of variabily** help create a mental picture of the spread of the data. 

**range**: `R` of a set of `n` measurements is defined as the difference between the largest and smallest measurements.  Simplest measure of variation. 

### Variance of a population

\\[ σ^2 = \frac{\sum(x_i - µ)^2}{N} \\]  

The variance of a population of ``N`` measurements is the average of the squares of the deviations of the measurements about their mean µ. The population variance is denoted by \\( σ^2 \\).

### Variance of a sample p65

\\[ s^2 = \frac{\sum(x_i - \bar{x})^2}{n - 1} \\]  

The variance of a sample of ``n`` measurements is the average of the squares of the deviations of the measurements about their mean ``x̅``  divded by ``n - 1``. The population variance is denoted by \\( σ^2 \\).

**standard deviation**: a set of measurements equal to the positive square root of the variance.

 	 
\\( n \\): number of measurements in a sample.  

\\( s^2 \\): sample variance  

\\( s = \sqrt{s^2}\\): standard sample deviation  

\\( N \\): number of measurements in the population  

\\( σ^2 \\): Population variance  

\\( σ = \sqrt{σ^2} \\):  population standard deviation  

### Calculator help

- on my Micronta,
- ``Mode 2 "SD"`` to enter statistical mode.  
- ``M+ "Data"`` to add data points  
- *sample standard deviation* is carried out with the \\(x σ_{n-1} \\) key. 
- *population standard deviation* is carried out wiht \\(x σ_n \\) key.  
- see the top case for more functions  


### The computing formula for calculating \\(s^2 \\).  

\\[ s^2 = \frac{\sum x_i^2 - \frac{(\sum x_i)^2}{n}}{n-1} \\]

## 2.4 Practical significance of standard deviation

###**Tchebysheff's Theorem**  
At least \\( 1- \frac{1}{k^2} \\) of the total number of *n* measurements lie in the constructed interval.  

### Empirical Rule

Given a distribution of measurements that is approximately mound shaped:

- The interval \\( µ ± σ ) \\) contains approximately 68% of the measurements  
- The interval \\( µ ± 2σ ) \\) contains approximately 95% of the measurements  
- The interval \\( µ ± 3σ ) \\) contains approximately 99.7% of the measurements  

The standard mound shaped disribution is commonly known as *normal distribution*.  

## A check on the calculation of `s`

The total range `R`, should be about four standard deviations or `4s`.

\\[ R ≈ 4s \\ or \\ s ≈ \frac{R}{4} \\]  


## 2.6 Measurements of Relative Standing

### z-score

\\[ z-score = \frac{x - \bar{x}}{s} \\]  

The **z-score** measures the difference between an observation and the mean measured in units of standard deviation.  

### Percentile

a set of \\(n\\) measurements on the variable \\(x\\) has been arranged in order of magnitude. The *pth percentile* is the value of *x* that is greater than *p%* of the measurements and is less then the remaining (100 -p)%.

- Scoring in the *60th percentile* means that 60% of all tests were lower then yours and 40% were higher. 

- the *25th* and *75th* percentiles are called the *lower \\(Q_1\\) and upper \\(Q_3\\) quartiles*.


### Calculating Sample Quartiles

**Lower quartile** \\( Q_1 \\) is the value of \\( x \\) in position \\(0.25(n + 1) \\)  
**Upper quartile** \\(Q_3\\) is the value of \\(x\\) in position \\(0.75(n + 1) \\)  

- When \\(0.25(n + 1)\\) and \\( 0.75(n + 1) \\) are not integers, the quartiles are found by interpolation, using the values in the two adjacent positions. 

#### Interquartile range (IQR) 

The **IQR** for a set of measurements is the difference between the upper and lower quartiles. \\(IQR = Q_3 - Q_1\\)

## 2.7 The Five-Number Summary and the Box Plot

The **Min**, \\(Q_1\\), **Median**, \\(Q_3\\), and **Max** make up the **Five-Number Summary**.  

### Box Plot


# Lesson 3 - 1011-2017 10:36 

## Objectives 

On completion of this lesson, without the aid of your course resources, you should be able to: 

1.     define: experiments, simple events, events, sample space, 
2.     predict the probability of an event, 
3.     describe relative frequency and its relationship with probability of an event, 
4.     explain counting rules: mn rule, extended mn rule, permutations rule, combinations rule, 
5.     summarize relationships among events: intersection, union, complement, 
6.     define probability rules: conditional probability, additive and multiplicative rules of probability, 
7.     explain relations among events: mutually exclusive, dependence, independence, 
8.     explain, pprobability distributions for discrete random variables, 
9.     define mean, variance and standard deviation of a discrete random variable and how to compute them. 

## Events and the Sample Space

*experiment*: the process by which an observation (or measurement) is obtained. 

*simple event* \\(E_n\\): an outcome observed on a single repetition of the experiment. 

*event E*: a collection of simple events. 

### Example

When one dice is tossed there are six possible outcomes

Event \\(E_{1...6}\\): Observe 1 to 6

Suppose:

A: observe an odd number.  
B: observe a number less then 4.  

Event A can occur if the upper face is 1,3,5 it is a collection of simple events. Write \\(A = {E_1, E_3, E_5}\\) and \\(B = {E_1, E_2, E_3}\\). 

*Mutually exclusive*: when one event occurs, the other cannot. 

*sample space \\(S\\)*: the ser off all simple events.   

## Caculating Probabilites using Simple Events 

\\(n\\): the number of times an experiment is performed.  

\\[Relative Frequency = \frac{Frequency}{n}\\]

The **Probability of Event A** is:

\\[P(A) = \lim_{n → ∞ } \frac{Frequency}{n}\\]

### Requirements for Simple Event Probibilites

- Each probability must lie between 0 and 1.
- The sum of the probilities for all simple events in S equals 1.  

*The probilitiy of the event A*: is equal to the sum of the probabilites of the simple events contained in A. 


## Useful Counting Rules

### The `mn` Rule

If the first stage can be accomplished in `m` ways and the second stage can be accomlishd in `n` ways there are `mn` ways to accomplish the experiement. 

#### Example

*Q:* Two dice are tossed. How many events in the sample sapce `S`?

*A:* The first die can fall one of *m = 6* ways. The second dice can fall one of *n = 6* ways.  The total number of simple events (`S`) is `mn = (6)(6) = 36`.

### The Extended `mn` Rule

If an experiement is performed in `k` stage then: 

\\[n_1,n_2,n_3...n_k\\]

### A counting rule for Permutations

The number of ways we can arrange `n` distinct objects, taking them `r` at a time is

\\[P^n_r = \frac{n!}{(n - r)!}\\]

where \\(n! = n(n-1)(n-2)...(3)(2)(1)\\) and \\(0! = 1\\).

Since `r` objects are chosen, the is an `r-stage` experiment. The first object can be chosen in `n` ways, the second in `n-1` and so on. 

### Special Case: Arranging `n` items

The number of ways to arange an entire set of `n` distinct items is:

\\[P^n_n = n!\\]

#### Example

*Q:* Three tickets are drawn from 50. If the order is important, how many *simple events* are there?  

*A:*  

\\[ P^{50}_3 = \frac{50!}{47!} = (50)(49)(48) = 117,600\\]  

Q: A piece of equipment with five parts can be put togehter in any order. How many combinations?  

A: \\[P^5_5 = \frac{5!}{0!} = (5)(4)(3)(2)(1) = 120)\\]

### A counting rule for Combinations

The number of distinct combinations of `n` distinct objects that can be formed taking them `r` at a time is

\\[C^n_r = \frac{n!}{r!(n - r)!}\\]

*combinations* and *permutations* are related:

\\[C^n_r = \frac{P^n_r}{r!}\\]

\\(C^n_r\\) resuls when you divide the number of permutations by *r!*. 

#### Example

*Q:* How many ways can three suppliers be chosen from five?

*A:*

\\[C^n_r = \frac{n!}{r!(n - r)!}\\]

\\[C^5_3 = \frac{5!}{3!2!} = \frac{5(4)}{2} = 10\\]

## 4.5 Event Relations and Probility Rules

**Union:** \\(A ∪ B\\) is an event where either A or B or both occur 

**Intersection:** \\(A ∩ B\\) is an event where both A and B occur.

**Complement:** \\(A^c\\) is an event that A does not occur. 

### Caculating Probabilites for Unions and Complements

#### The Addition Rule

Given two events *A* and *B*, the probility of their union, \\(A ∪ B\\) is equal to:

\\[P(A ∪ B) = P(A) + P(B) - P(A ∩ B)\\]

The probability is the sum of their union minus their intersection.  

#### Rule for Complements

\\[ P(A^c) = 1 - P(A) \\]

## 4.6 Independance, Conditional, Probability and the Muliplicaton Rule

*independant*: two events are said to be indpendant if and only if the probability of event B is not influenced or changed by the occurance of event A. 

*the conditional probability of A, **given** that B has occured*: \\(P(A|B)\\)

### The General Multiplication Rule

The probability that both *A and B* occur when the experiement is performed is 

\\[P(A ∩ B) = P(A)P(B|A)\\]

or 

\\[P(A ∩ B = P(B)P(A|B))\\]

### Conditional Probabilities 

You can calculate *conditional probability* \\(P(A|B)\\) by rearranging the **Multiplication Rule**.

\\[P(A|B) = \frac{P(A ∩ B)}{P(B)}\\]

### The Difference Between *Mutually Exclusve* and *Indpendant Events*

- *Mutually exclusive or disjoint* events cannot both happen when the experiment is perfromed. The occurance of event B affects the probability that event A can occur.

- *Mutually exclusive* events are *dependant*. 


## 4.8 Discrete Random Variable and their Probability Distributions

*Random Variable*: A varilable `x` is a *Random Variable* if the value that is assues, corresponding to the outcome fo the an experiemtn, is a chance or random event. 


*Probability Distribution*: For a discrete random variable is a formula, table or graph taht gives the possible values of X, and the probabilyt  p(x) associated with each value of x. 

### Requirements for a discrete probability distribution 

\\[ 0 ≤ p(x) ≤ 1 \\
∑p(x) = 1 \\]

*expected value of X*: Let X be a discrete random variable wiht probability distribution p(x). The *expected value of x* is given as: \

\\[ µ = E(X) = ∑xp(x) \\] 

where the elements are summed over all value of the random variable x.

*variance of x*: Let X be a discrete random variable with probability distribution p(x) and mean µ. The *variance of x* is:

\\[ σ^2 = E[(X - µ)^2] = σ(x - µ)^2p(x)\\]

*standard deviation σ of a random variable X*: is equal to the positive square root of its variance. 

# Lesson 4 / Chapter 5 - Several Useful Discrete distributions

This lesson and the related material of Chapter 5  of your textbook will walk you through *three important discrete and one continuous random variables that serve as models for different real life phenomena*. The discrete random variables are: the **binomial, the Poisson and the hypergeometric distributions**.   

## Objectives 
On completion of this lesson, without the aid of your course materials, you should be able to: 

1. define the **Binomial distribution**: how to compute the probabilities of the binomial distribution and how to compute its mean and variance 
2. define the **Poisson distribution**: how to compute the probabilities of the  Poisson distribution and how to compute its mean and variance 
3.     describe how to use the Poisson distribution to approximate the Binomial distribution 
4.     define the **Hypergeometric distribution**: how to compute the probabilities of a hypergeometric distribution and how to compute its mean and variance 
   

## 5.1 The Uniform Probability distribution

When a graph of a probability distribution has a flat shape it is called a *discrete uniform probability distribution*. 

## The Bernoulli Probability Model

- When there are two outcomes in a given experiment it is called a *Bernoulli trial*. 
- The possible outcomes are *Success = 1 and Failure  = 0*.  

## 5.2 - The Binomial Probability distribution

A **Binomial experiment** has:

1. The experiment consists of of `n` identical trials.,
2. Each trial results in one of two outcomes. One is called *Success (S)* and the other is called *Failure (F)*. 
3. The probability of success on a single trial is equal to `p` and remains the same from trial to trial. The probability of failure `q` is equal to `1 - p = q`
4. The trial are *independent*
5. We are interested in `x`, the number of successes observed during `n` trials. 

## binomial probability distribution

\\[ P(X = k) = C^n_kp^kq^{n-k} = \frac{n!}{k!(n - k)!}p^kq^{n-k} \\]

\\[ C^n_k = \frac{n!}{k!(n - k)!} \\]

### The Mean and Standard Deviation for the Binomial Random Variable

The random variable `X`, the number of successes in `n` trials, had a probability distribution with this centre and spread. 

**Mean:**

\\[ µ= np \\]

**Variance:**

\\[ σ^2 = npq\\]

**Standard Deviation:**

\\[ σ = \sqrt{npq} \\]

## Cumulative binomial Probabilities

This is very time consuming to do by hand. See **Appendix 1 : Table 1** for tables of common situations.

Because the charts are *Cumulative* if you want to find `k = 3` you subtract `k = 2` from the answer.

Also see [Wolfram Alpha: Statistics Course Assistant](https://www.wolframalpha.com/input/web-apps/statistics-course-assistant/distributions/binomial-distribution)

## 5.3 The Poisson Probability distribution

See [Stat Track : Poisson Distribution Calculator](http://stattrek.com/online-calculator/poisson.aspx) for a great resource

The *Poisson Probability Distribution* provides a good model for data that represents the number of occurrences of a specified event in a given unit of time or space. 

**`X` represents the number of events that occur in a period of time or space during which an average of µ such events can ebe expected to occur**. 

Events must occur **randomly and independently** of one another.

Let µ be the number of times that an event occurs in certain period of time or space. The probability of `k` occurrences of this event is 

\\[P(X =k) = \frac{ µ^ke^{-\mu}}{k!} \\]

The **mean** and **standard deviation** of the Poisson random variable are:

**Mean:**

\\[ µ \\]

**Standard Deviation:**

\\[ σ = \sqrt{µ} \\]

## 5.4 The hypergeometric probability distribution

[Stat Track : hypergeometric](http://stattrek.com/online-calculator/hypergeometric.aspx)

[ke!san Online Calculator](http://keisan.casio.com/exec/system/1180573201)  

If the number of elements in the population is small in relation to the sample size (n|N ≤ 0.05), the probability of a sucess for a given trial is dependent on the outcomes of preceding trials. Then the number`X` of sucesses follows what is known as a *hypergeometric probability distribution*.

`n` sample size.  
`N` population.  
`M` successes  
`N - M` failures   
The probability of exactly `k` successes  
in a random sample of size `n` is


\\[ P(X = k) = \frac{C^M_kC^{N-M}_{n-k}}{C^N_n} \\]

for values of `k` that depend on `N, M and n` with 

\\[ C^N_n = \frac{N!}{n!(N - n)!} \\]

### The Mean and Variance for a hypergeometric random Variable

The random variable `X`, the number of successes in `n` trials, had a probability distribution with this centre and spread. 

**Mean:**

\\[ µ= n(\frac{M}{N}) \\]

**Variance:**

\\[ σ^2 = n\bigg(\frac{M}{N}\bigg)\bigg(\frac{N - M}{N}\bigg)\bigg(\frac{N - n}{N - 1}\bigg) \\]

## What is a cumulative hypergeometric probability?

A cumulative hypergeometric probability refers to a sum of probabilities associated with a hypergeometric experiment. To compute a cumulative hypergeometric probability, we may need to add one or more individual probabilities.

For example, suppose we randomly select 5 cards from an ordinary deck of playing card. We might ask: What is the probability of selecting AT MOST 2 red cards? The cumulative probability of getting AT MOST 2 red cards would be equal to the probability of selecting 0 red cards plus the probability of selecting 1 red card plus the probability of selecting 2 red cards. Notationally, this probability would be indicated by P(X < 2).

The table above shows the cumulative probability for getting at most 2 red cards in a random deal of 5 cards. That probability is 0.500. Thus, P(X < 2) = 0.500.


# Lesson 5 / Chapter 6 - normal (continuous) distributions ( 1024-2017 11:01 )

## Objectives 

On completion of this lesson, without the aid of your course materials, you should be able to: 

1.        define the terms: “*normal distribution*” and *“standard normal distribution”*, 
2.        compute the probabilities of the standard normal distribution from the standard normal Table provided at the end your textbook, 
3.        compute the probabilities of any normal distribution using the standard normal Table, 
4.        calculate normal approximation to the Binomial probability distribution, 
5.        describe how to compute a Binomial probability using the normal distribution.

## 6.1 Probability Distributions for Continuous Random variables

- When a random variable `x` is discrete, you can assign a positive probability to each value that `x` can take and get the probability distribution for `X`.  The sum of all the probabilities for the different values of `X` is 1. 
- Not all experiments result in random discrete variables. 
- *continuous random variables* such as heights and weights, product life can assume infinitely many values.
- The *probability distribution* is the area under the curve, the **density** at various points which varies with `x` can be described by `f(x)` called the *probability distribution* or the *probability density function.*

\\[f(x); P(a < X < b)\\]

- The area under a continuous probability distribution is equal to 1. 
- The probability that `X` will fall into a particular interval is equal to the area under the curve between points `a` and `b`.
- Since there is no area above a single point `X=a` the definition implies that the probability is 0.  
- \\(P(X=a)=0\\) for continuous random variables. 


### Uniform Distribution

- used to model the behaviour of continuous random variable whose values are uniformly distributed over a given interval.  

### Exponential Distribution

- uses such as waiting times, lifetime of electronic components 

\\[
f(x) = \frac{1}{µ}e^{-x/µ}, 0 ≤ x ≤ ∞, µ > 0
\\] 

## 6.2 The Normal Probability Distribution 

\\[
f(x) = \frac{1}{σ \sqrt{2π}} e^{-(x- µ)^2/(2σ^2)}, -∞ < x < ∞
\\]

Where π and *e* are mathematical constants/ *e* = 2.7183

## 6.3 Tabulated areas of the normal probability distribution

### The Standardized Normal Random Variable `z`

- a normal random variable is *standardized* `z` by expressing its value as the number of standard deviations σ it lies to the the right of left of its mean µ. 

\\[ z = \frac{X - µ}{ σ }
\\ or 
\\ X = µ + z σ \\]

- The *standardized normal distribution*  had a mean of 0 and its standard deviation is 

## Approximating Binomial probability by using normal probabilities

**Continuity Correction**: include half of the two extreme probability rectangles when using the normal approximation to the binomial probability distribution

`X:` binomial random variable.
`n:` trials  
`p`: probability of success. 
`q`: probability of failure.

\\[ µ = np \\ σ = \sqrt{npq} \\]

This approximation works as long as `n` is large and `p` is not too close to 0 or 1.  '

The *rule of thumb* is that the normal approximation to the bionomial Probabilites will be adequate if both `np > 5` and `nq > 5`.

**Q: If X is a binomial with n=10000 and p=0.002, what is the probability that X
will fall between 10 and 30 inclusive?**

**A:** 

1. if both `np > 5` and `nq > 5`. np = 20, nq = 9980
2. Get µ and σ. 
	µ = np = 10000*0.002= 20
	σ = \\( \sqrt{npq}\\) = 19.96
3. Correct for continuity. 
	\\( P(10 < x < 30) ≈ P(9.5 < x < 30.5) \\)
3. Find the normal probability.

	\\[ \begin{align}
       z &= \frac{X - µ}{ σ } \\
	   z_1 &= -0.53 \\
	   z_2 &=  0.53 \\
	   &= p(-.5261 < x < .5261) \\
	   &= 0.7019 - 0.2981 \\
	   &= 0.4038 
	   
	\end{align}\\]
	
	
# Lesson 6 / Chapter 7 - Sampling Distributions 1025-2017 10:28 

## Objectives 

On completion of this lesson, you should be able to: 

1.  define the sampling distribution of a statistic, 
2.  explain the central limit theorem, 
3.  explain the sampling distribution of the sample mean and how to use it, 
4.  demonstrate how to determine the sampling distribution of the sample proportion and how to use it. 

## 7.2 Sampling PLans and Experiemental Designs

### Simple Random Sampling

**Observational Study:** The data already existed before you decided to observe it. 

## 7.3 Statistics and Sampling Distributions 

**Sampling Distributions**: The probability disributions for statistics. In repeated sampling they provide:
	- what values of the statistic can occur
	- How often each value occurs. 
	
## 7.4 The Central Limit Theorem

If random samples of `n` observations are drawn from a non-normal population with finite mean `µ` and standard deviation `σ` then when `n` is large, the sampling distribution of the sample mean `x̅` is approximately normall distributed, with mean `µ` and standard deviation \\( \frac{ σ }{\sqrt{n}} \\).  

The approximation becomes more accurate as `n` becomes large. The approximation is exact for normal populations. 

The Central Limit Theorem can be restated to apply to the *sum of the sample measurements \\( ∑x_i \\)* which as `n` becomes large also has an approximately normal distribution with the mean `nµ` and the standard deviation \\( σ \sqrt{n} \\). 

### When the sample size is large enough to use the Centra Limit Theorem

- if the sampled population is *normal*, then the sampling distribution of x̅ will also be normal no matter what size you choose. 
- When the sampled population is approximately *symmetric* the sampling distribtion of x̅ becomes approximately normal for relatively few values of `n`. 
- When the sample population is *skewed* the sample size `n` must be larger, with `n` at least 30 before the sampling distribution of x̅ becomes approximately normal. 

## 7.5 The Sampling Distribution of the Sample mean x̅

- If random samples of `n` measurements is selected from a population with mean `µ` and standard deviation `σ`, the sampling distribution of the sample mean `x̅` will have mean `µ` and standard deviation \\( \frac{ σ }{\sqrt{n}} \\).  
- If the population has a *normal* distribution, the sampling distribution of x̅ will be *exactly* normally distributed, regardless of the sample size, `n`.
- If the populations distribution is *non-normal*, the sampling distribution of x̅ will be approximately normally distributed for large samples (by the Central Limit Theorem).

\\[ z = \frac{ \bar{x} - µ }{ σ / \sqrt{n}} \\]

### Standard Error

The standard devitation of a statistic used as an esitimator of a population parameter is also called the *standard error of the estimator* (abbreviated SE) because it refers to the precision fo the estimator. The standard deviation of x̅ given by \\( \frac{ σ }{\sqrt{n}} \\) - is referred to as the **standard error of the mean** (abbreviated as SE(x̅) or just SE).

### How to calculate the probabilities for the Sample Mean x̅

1. Find µ and calculate \\(SE( \bar{x} ) = σ/\sqrt{n} \\) 
2. Write down the event of interest in terms of x̅ and locate the appropriate area on the normal curve.
3. Convert the necessary values of x̅ to *z-values* using  \\[ z = \frac{ \bar{x} - µ}{ σ/\sqrt{n}} \\]

4. Use table 3 in appendix I to calculate the probability.  


## 7.6 The Sampling Distribution of the Sampling proportion p̂

`n`: Random sample of `n` observations.
`p` proportion of `n` with the characteristic
`x`: the number of samples with this characteristic observed

\\[ p̂ = \frac{x}{n} \\]

will have a mean 

\\[p\\]

and a standard deviation

\\[ SE( p̂ ) = \sqrt{\frac{pq}{n}} \\] where `q = 1 - p`.

When the sample size is large, the sampling distribution of p̂ can be approximated by a normal distribution. This is okay if `np > 5` and `nq > 5`.

### How to calculate probabilities for the sample proportion p̂

1. Find the neccessary values of `n` and `p`.
2. Check whether the normal approximation to the bionomial distribution is appropriate (`np > 5` and `nq > 5`).
3. Write down the event of interest in terms of p̂ and locate the appropriate area on the normal curve.
4. Convert the necessary value of p̂ to z-values using \\[ z = \frac{p̂ - p}{\sqrt{\frac{pq}{n}}} \\]
5. Use table 3 in Appendix I to calculate the probability.


# Lesson 7 / Chapter 8 - Point Estimation ( 1108-2017 12:38 )

## Objectives 

On completion of this lesson, you should be able to: 

1.     define point and interval estimators, 
2.     define unbiased estimator, 
3.     define standard error (SE) of an estimator and 95% margin of error 
4.     explain how to use the margin of error as a measure of the precision of an estimator, 
5.     define confidence interval and confidence coefficient, 
6.     employ the general formula of confidence interval for large sample sizes, 
7.     construct confidence intervals for: mean, proportion, difference between two means, difference between two proportions, 
8.     explain the correct interpretation of confidence interval, 
9.     construct one-sided confidence intervals. 
 
**estimator:** An *estimator* is a rule, usually expressed as a formula, that tells us how to calculate an estimate based on information in a sample.  

## 8.3 Types of Estimators 

**point estimation:** Based on sample data, a single number is calculated to estimate the population parameter. The rule of formula that describes the *point estimator* and the resulting number is called a *point estimate*. 

**interval estimation:** Based on sample data, two numbers are calculated to form an interval within which the parameter is expected to lie. The rule or formula the describes this calculation is called the *interval estimator,* and the resulting pair of numbers is called an *interval estimate* or *confidence interval*. 

### 8.4 Point Estimation

**parameter:** target's bull's eye
**estimator:** bullet or arrow  

**unbiased:** as estimator is said to be **unbiased** if the *mean of the distribution* is equal to the true value of the parameter. Otherwise, the estimator is said to be *biased*. 

**error of estimation:** the distance between the estimate and the true value of the parameter. 

### Point Estimation of a Population Parameter 

**Point estimator:** a statistic calculated using sample measurements. 

**95% margin of error:** 1.96 x standard error of the estimator.  

### How to estimate a population mean or proportion 

1. To estimate the population mean µ for a quantitiative population, the point estimator x̅ is unbiased with standard error estimated as 

\\[ SE = \frac{s}{\sqrt{n}} \\]

The 95% margin of error when n ≥ 30 is estimated as 

\\[ 1.96 ± (\frac{s}{\sqrt{n}}) \\]

2. To estimate the population proportion `p` for a binomial population, the point estimator \\(  p̂ = x/n \\) is *unbiased*, with standard error estimated as 

\\[ SE = \sqrt{\frac{p̂q̂}{n}} \\]

The 95% margin of error is estimated as 

\\[ 1.96 ± \sqrt{\frac{p̂q̂}{n}} \\]

*Assumptions:* np̂ > 5 and nq̂ > 5

## 8.5 Interval Estimation

**confidence coefficient:** the probability that the confidence level wil cotanin the estimated parameter. 

### A (1 - α) 100% large-Sample confidence interval 

(Point Estimator) ± \\(z_{{\frac{a}{2}}} \\) x (standard error of the estimator)

This generates two value; the **lower confidence limit (LCL) and the upper confience limit (UCL).**

### Large sample confidence interval for a population mean µ

### A (1 - α)100% large-sample confidence interval for a population mean µ

\\[
\bar{x}    ± z_{{\frac{a}{2}}}\frac{ σ }{\sqrt{n}}
\\]

## 8.6 Estimating the Difference Between the Population Means

### Samples from two Quantitative Populations

|          | Population 1 | Population 2 |  
| -------- | ------------ | ------------ |  
| Mean     | \\(µ_1\\)    | \\(µ_2\\)    |  
| Variance | \\(σ_1^2\\)  | \\(σ_1^2\\)  |  

|             | Sample 1      | Sample 2     |  
| ----------- | ------------- | ------------ |  
| Mean        | \\( \bar{x}_1 \\) | \\( \bar{x}_2\\) |  
| Variance    | \\(s_1^2\\)   | \\(s_2^2 \\) |  
| Sample Size | \\(n_1\\)     | \\(n_2\\)    |  

### Properties of the Sampling Distribution of (\\( \bar{x}_1 - \bar{x}_2\\)). The difference between two sample means.

1. The mean of (\\( \bar{x}_1 - \bar{x}_2\\)) is 

	\\[µ_1 - µ_2\\]

	and the standard error is 

	\\[ SE = \sqrt{\frac{ σ_1^2}{n_1} + \frac{ σ_2^2}{n_2}} \\]

	which can be estimated as 

	\\[ SE = \sqrt{\frac{ s_1^2}{n_1} + \frac{ s_2^2}{n_2}} \\]

2. **If the sampled populations are normally distributed**, then the sampling distribution of \\( \bar{x}_1 - \bar{x}_2 \\) is **exactly** normally distributed, regardless of the sample size. 

3. **If the sampled populations are not normally distributed**, then the sampling distribution of \\( \bar{x}_1 - \bar{x}_2 \\) is **approximately** normally distributed when \\(n_1\\) and \\(n_2\\) are both *30* or more, due to the *Central limit Theorem*.

\\[ 
\frac{ (\bar{x}_1 - \bar{x}_2) - (µ_1 - µ_2)}{ \sqrt{\frac{ s_1^2}{n_1} + \frac{ s_2^2}{n_2}} }
\\]

### Large-sample point estimation of ( \\( \bar{x}_1 - \bar{x}_2 \\) )

Point estimator: ( \\( \bar{x}_1 - \bar{x}_2 \\) )  

**95% Margin of error:**

\\[ ± 1.96 SE = ± 1.96\sqrt{\frac{ s_1^2}{n_1} + \frac{ s_2^2}{n_2}} \\]
	
### A (1 - α) 100% large-sample confidence interval for \\(µ_1 - µ_2\\)

\\[  (\bar{x}_1 - \bar{x}_2) ± z_{a/2} \sqrt{\frac{ s_1^2}{n_1} + \frac{ s_2^2}{n_2}} \\]
	
## 8.7 Estimating the Difference Between two Binomial Proportions 

### Properties of the Sampling Distribution of the Difference \\(( p̂_1 - p̂_2 ) \\) between two sample proportions 

THe sampling distribution of the difference between sample proportions is 

\\[ (  p̂_1 -  p̂_2 ) = \bigg(\frac{x_1}{n_1} - \frac{x_2}{n_2}\bigg) \\]

has these properties:  

1. The mean of \\( (  \hat{p}_1 -  p̂_2 ) \\) is \\( p_1 - p_2 \\)

	and the standard error is 

	\\[ SE = \sqrt{\frac{ p_1q_1}{n_1} + \frac{ p_2q_2}{n_2}} \\]

	which is estimated as

	\\[ SE = \sqrt{\frac{  \hat{p}_1\hat{q}_1}{n_1} + \frac{  p̂_2q̂_2}{n_2}} \\]
	
2. The sampling distribution of \\(( p̂_1 - p̂_2 ) \\) can be approximated by a normal distribution when \\(n_1\\) and \\(n_2\\) are large, due to the *Central Limit Theorem*.

### Large-sample point estimation of \\(( p̂_1 - p̂_2 ) \\) 

Point estimator: ( \\(  p̂_1 - p̂_2 \\) )

**95% Margin of error:**

\\[ ± 1.96 SE = ± 1.96\sqrt{\frac{  p̂_1q̂_1}{n_1} + \frac{  p̂_2q̂_2}{n_2}} \\]
	
### A (1 - α) 100% large-sample confidence interval for \\(µ_1 - µ_2\\)

\\[  ( p̂_1 - p̂_2 ) ± z_{a/2} \sqrt{\frac{  p̂_1q̂_1}{n_1} + \frac{  p̂_2q̂_2}{n_2}} \\]

# Lesson 8 / Chapter 9 - Large-Sample Tests of Hypothesis ( 1112-2017 22:53  )

## Concepts:

1. null and alternative hypotheses, 
2. steps involved in testing hypotheses, 
3. test statistic, 
4. one- and two-tailed tests of hypothesis, 
5. p-value,  
6. critical region, 
7. Type I error. 

## 9.2 A Statistical Test of Hypothesis

the statistical test of hypothesis consists of five parts:

1. The null hypothesis, denoted by \\(H_0\\).  
2. The alternative hypothesis, denoted by \\(H_a\\).  
3. The test statistic and its p-value.
4. The rejection region.
5. The conclusion.

The two competing hypothesis are the **alternative hypothesis \\(H_a\\)**, generally the hypothesis that the researcher wishes to suport, and the **null hypothesis \\(H_0\\), a contradiction of the alternative hypothesis.**

## 9.3 A Large-Sample Test about A Population Mean

1. **Null Hypothesis:** \\(H_0: µ = µ_0 \\)
2. **Alternative Hypothesis:** \\(H_a: µ > µ_0 \\)  
3. **Use the standardized test statistic** \\( z = \frac{ \bar{x} - µ_0}{s / \sqrt{n}} \\)  
4. **Rejection region:** To control the risk of making an incorrect decision as α = 0.01, you must set the **critical value** separating the rejection and acceptance regions so that the area under the right tail is exactly α = 0.01. This value is found in Table 3 Appendix I \\( z = 2.33 \\). This the *null hypothesis* will be rejected if the observed value of the test statistic, *z* is greater than *2.33*.
5. **Conclusion:** If the *observed value* falls in the rejection region you an reject \\( H_0 \\). The probability that you made an incorrect decision is α = 0.01. 

## 9.3 A Large-Sample Statistical Test for µ

1. **Null Hypothesis:** \\(H_0: µ = µ_0 \\)
2. **Alternative Hypothesis:** 

	One-tailed test: \\(H_a: µ > OR < µ_0 \\)  
	Two-tailed test: \\(H_a: µ ≠ µ_0 \\)  
3. **Use the standardized test statistic** \\( z = \frac{ \bar{x} - µ_0}{s / \sqrt{n}} \\)  
4. **Rejection region:** Reject \\( H_0 \\) when  

	One-tailed test: \\(z > z_α \\) OR \\( z < -z_α\\)  
	Two-tailed test: \\(z > z_{α/2} \\) OR \\(z < -z_{α/2}\\)  
	
To control the risk of making an incorrect decision as α = 0.01, you must set the **critical value** separating the rejection and acceptance regions so that the area under the right tail is exactly α = 0.01. This value is found in Table 3 Appendix I \\( z = 2.33 \\). This the *null hypothesis* will be rejected if the observed value of the test statistic, *z* is greater than *2.33*.
5. **Conclusion:** If the *observed value* falls in the rejection region you an reject \\( H_0 \\). The probability that you made an incorrect decision is α = 0.01.  
  

## Calculating the p-Value

**p-Value:** The **p-Value** or observed significance level of a statistical test is the smallest value of α for which \\(H_0\\) can be rejected. It is the *actual risk* of committing a Type I error, if \\(H_0\\) is rejected based on the observed value of the test statistic. 

- A small p-Value indicates that the observed value of the test statistic lies far away from the hypothesiszed value of µ. This presents strong evidence that \\(H_0\\) is false and should be rejected. 

**statistically significant**: if the p-value is less than or equal to a pre-assigned significance legel α, then the null hypothesis can be rejected, and you can report that the results are *statistically significant* at level α. 

### p-value scale

- **p-value < 0.01:** \\(H_0\\) is rejected. The results are **highly significant**.
- **0.01 < p-value < 0.05:** \\(H_0\\) is rejected. The results are **statistically significant**.
- **0.05 < p-value < 0.10:** \\(H_0\\) is not usually rejected. The results are only  **tending towards statistical significant**.
- p-value > 0.10:** \\(H_0\\) is not rejected. The results are **not statistically significant**.

## SIGNIFICANCE LEVEL = α 

## Two Types of Errors

### Type I Error

A **Type I** error for a statistical test is the error of rejecting the null hypothesis when it is true. The **probability of making a Type I error is denoted by the symbol α**.

### Type II Error

A **Type II Error** for a statistical test is the error of accepting the null hypothesis when it is false and some alternative hypothesis is true. The probability of a Type II error is denoted by the symbol β.

## The Power of a Statistical Test

The **power of a statistical test** given as, \\( 1 - β = P\\) (reject \\(H_0\\) when \\(H_a\\) is true) measures the ability of the test to perform as required. 

A graph of (1- β) as  a function of the true value of the paramater of interest is called the **power curve**.

### How to calculate β

1. Find the critical values of value of x̅ used to seperate the acceptance and rejection regions. 
2. Using one or more value of µ consistent with the alternative hypothesis \\(H_a\\), calculate the probability that the sample mean x̅ falls in the *acceptace region.* 
3. Remember that the *power* fo the test is ( 1 - β ).

# Lesson 9 / Chapeter 9 - ( 1122-2017 12:19 )

## Objectives 

On completion of this lesson, you should be able to: 

1.  test hypotheses about the proportion of a binomial population based on large-sample, 
2.  test hypotheses about the difference between proportions of two binomial populations based on two independent large-samples from the two populations. 

### 9.4 A Large-Sample Test of Hypothesis for the Difference Between Two Population Means

1. **Null Hypothesis:** \\(H_0: \mu_1 - \mu_2 = D_0 = 0 \\) 
2. **Alternative Hypothesis:** 

	- One-tailed test: \\(H_a: \mu_1 - \mu_2 > D_0 \\) OR \\( H_a: \mu_1 - \mu_2 < D_0  \\)  
	- Two-tailed test: \\( H_a: \mu_1 - \mu_2 ≠ D_0 \\)  
	
3. **Use the standardized test statistic** 
	\\[ z = \frac{ (\bar{x}_1 - \bar{x}_2) - D_0}{SE} = \frac{ (\bar{x}_1 - \bar{x}_2) - D_0}{\sqrt{\frac{s_1^2}{n_1}+ \frac{s_2^2}{n_2}}} \\]  

4. **Rejection region:** Reject \\( H_0 \\) when:
	- One-tailed test:  \\(z > z_\alpha \\) OR \\( z < -z\alpha \\) *when the alt hypothes is* \\( H_\alpha: p < p_0 \\).   
	- Two-tailed test: \\( z > z_{\alpha/2} \\) OR z \\( < -z_{α/2} \\).    

**Assumption**: The samples are randomly and independently selected from the two populations, and \\(n_1 \geq 30 \\) and \\( n_2 \geq 30 \\).

## 9.5 A Large-Sample Test of Hypothesis for a Binomial Proportion

When a random sampel of `n` identical trial is drawn from a binomial population, the sample proportion  p̂ has approximetely normal distribution when `n` is large, wiht mean `p` and standard error

\\[SE = \sqrt{\frac{pq}{n}} \\]

When you test a typohtesis about `p`, the proportion of the population posessing a certain attribute, the test follows the same general form as the large-sample test in 9.3 and 9.4. To test the hypothesis of the form

1. **Null Hypothesis:** \\(H_0: p = p_0 \\)
2. **Alternative Hypothesis:** 

	- One-tailed test: \\( H_a: p > p_0 \\) OR \\( p < p_0 \\)  
	- Two-tailed test: \\( H_a: p ≠ p_0 \\)  

The test is constructed use p̂, the best esimator for the true population proporiton`p`. 

### Large-Sample Statistical Test for p

1. **Null Hypothesis:** \\(H_0: p = p_0 \\) 
2. **Alternative Hypothesis:** 

	- One-tailed test: \\(H_a: p > p_0 \\) OR \\( p < p_0 \\)  
	- Two-tailed test: \\( H_a: p ≠ p_0 \\)  
	
3. **Use the standardized test statistic** 
	\\[ z = \frac{ \hat{p} - p_0}{SE} = \frac{\hat{p} - p_0}{\sqrt{\frac{p_0q_0}{n}}} \\ → \hat{p} = \frac{x}{n} \\]  

4. **Rejection region:** Reject \\( H_0 \\) when:
	- One-tailed test:  \\(z > z_\alpha \\) OR \\( z < -z\alpha \\) *when the alt hypothes is* \\( H_\alpha: p < p_0 \\).   
	- Two-tailed test: \\( z > z_{\alpha/2} \\) OR z \\( < -z_{α/2} \\).    

**Assumption**: The sampling satisfies teh assumptions of a binomial experiment (Section 5.2) and `n` is large enough so that the sampling distribution is  p̂ can be approximated by a normal distribtuion. \\(np_0 > 5 \\) and \\( nq_o >5 \\).

# Lesson 10 - Inference from Small Samples Ch. 10.1-10.3 (1128-2017 10:22)

## Objectives 
On completion of this lesson, you should be able to: 

1. read a student’s t-distribution and the probabilities and critical values from the table of the t-distribution.  
2. test hypothesis about and build confidence intervals for mean of a single normal population based on small sample.   


3. test hypothesis about and build confidence intervals for the difference between means of two normal populations based on two independent small samples.  
4. test hypothesis about and build confidence interval for the difference between means of two normal populations based on two dependent small samples.  

## Good term review

- µ - A single population mean.
- (\\(µ_1 - µ_2\\)) the difference between two population means.
- \\( σ^2 \\) a single population variance 
- \\( σ^2_1 \\) and \\( σ^2_2 \\) the comparison of two population variances.

## Student's `t` Distribution

**Summary of info regarding sampling distribution of x̅ from Chapter 7.**

- When the original sampled population is normal, x̅ and \\( z= (\bar{x} - µ)/( σ / \sqrt{n}) \\) both have normal distribution, *for any sample size.*
- When the original sampled population is not normal, x̅ and \\( z= (\bar{x} - µ)/( σ / \sqrt{n}) \\) and \\( z ≈ (\bar{x} - µ)/( σ / \sqrt{n}) \\) all have approximately normal distributions, if the sample size is *large*. 
- **∴ When `n < 30` the Central Limit Theorem will not guarantee that \\( \frac{(\bar{x} - µ)}{( σ / \sqrt{n})} \\) is approximately normal.** 

**When the sample size `n` is small \\( z= (\bar{x} - µ)/( σ / \sqrt{n}) \\) *does not have a normal distribution.***

### Formula for Student's `t` Distribution 

\\[ t = \frac{\bar{x} - µ}{s/\sqrt{n}} \\]

for random samples of size `n` from a normal population.

Characteristics:

- it is mound shaped and symmetric around `t = 0` just like `z`.
- It is more variable then `n` with "heavier tails", it does not approach the horizontal axis as quickly as `z` does.
- The shape of `t` distribution depends on the sample size `n`. A `n` increases the variability of `t` decreases because the estimate `s` of `σ` is based on more and more information. When `n` is infinitely large, the `t` and `z` distributions are identical.

The divisor `(n-1)` in the formula for the sample variance `s²` is called **The Number of Degrees of Freedom `(df)` associated with \\( s^2 \\)**. It determines the *shape of the `t` distribution*. 

#### Assumptions behind Student's `t` Distribution

- The sample must be randomly selected.
- The population from which you are sampling must be normally distributed. 

## 10.3 Small Sample Inferences Concerning a Population Mean

## Small-sample hypothesis test for µ

1. **Null Hypothesis:** \\(H_0: µ = µ_0 \\)
2. **Alternative Hypothesis:** 

	One-tailed test: \\(H_a: µ > OR < µ_0 \\)  
	Two-tailed test: \\(H_a: µ ≠ µ_0 \\)  
3. **Test statistic** \\( t = \bigg(\frac{ \bar{x} - µ_0}{s / \sqrt{n}}\bigg) \\)  
4. **Rejection region:** Reject \\( H_0 \\) when  

	One-tailed test: \\(t > t_α \\) OR \\( t < -z_α\\)  
	Two-tailed test: \\(t > t_{α/2} \\) OR \\(z t -t_{α/2}\\)  
	
The **critical values** of `t`, \\(t_\alpha\\) and \\(t_{\alpha/2}\\) are based on `(n - 1)` degrees of freedom. These tabulated values can be found using Table 4 of Appendix 1

**Assumption:** The sample is randomly selected from a normally distributed population. 

## Small-sample (1 - α) 100% confidence interval for µ

\\[ \bar{x} ± t_{\alpha/2}\frac{s}{\sqrt{n}} \\]

where \\( \frac{s}{\sqrt{n}}\\) is the estimated error of x̅, often called the **standard error of the mean**.

This means that the true mean will range from \\( \bar{x} - t_{\alpha/2}(s/\sqrt{n}) \\) to \\( \bar{x} + t_{\alpha/2}(s/\sqrt{n}) \\) in repeated sampling.

 **95% confidence interval is \\( α / 2 = 0.050 / 2 = 0.025\\)**
 
## 10.4 Small Sample Inference for the Difference between two population means: Independent Random Samples
 
When the sampel sizes are small, we cannot use the large-sample `z` statistic because the sample does not have an approximately normal distribution or a *Student's `t` distribution*. We have to make one more assumption. 
 
 We must suppose that the variability of hte measurements in the two normal populations is the same and can be measured by a common variance \\(\sigma^2\\). That is both populations have exactly the sample shape* and \\(σ^2_1 = σ^2_2 = σ^2\\). 
 
 Then the **standard error of the difference in the two sample means** is
 
 \\[ \sqrt{\frac{\sigma^2_1}{n_1} + \frac{\sigma^2_2}{n_2}} = \sqrt{\sigma^2\bigg(\frac{1}{n_1}+\frac{1}{n_2}\bigg)}  \\]
 
 It can be proven that if you use the appropriate sample estimate \\(s^2\\) for the populaiton variance \\(σ^2\\), then the resulting test statistic,
 
 \\[ t = \frac{(\bar{x}_1 - \bar{x}_2) - (\mu_1 - µ_2)} { \sqrt{s^2\bigg(\frac{1}{n_1}+\frac{1}{n_2}\bigg)}  }   \\]
 
 has a *Studen's `t` distribution*. The only remaining problem is to find the sample estimate \\(\sigma^2\\) and the appropriate number of *degrees of freedom* for the **`t` statistic**.
 
To calculate \\(s^2\\) we use a formula that calcualtes the *weighted average*  of \\(s^2_1\\) and \\(s^2_2\\).

### Calculation of \\(s^2\\)

\\[ s^2 = \frac{ (n_1 - 1 )s^2_1 + (n_2 - 1 )s^2_2 } {n_1 + n_2 -2 } \\]

## Test of Hypothesis Concerning the Difference Between to means: Independant Radom Samples 

1. **Null hypothesis:** \\(H_0: (\mu_1 - µ_2) = D_0 \\) where \\(D_0\\) is some specified difference that you wish to test. For many tests, you will hypothesize that there is no difference between \\(µ_1\\) and \\(µ_2\\); that is \\(D_0 = 0\\).

2. **Alternative Hypothesis:** 

	**One-tailed test**: \\(H_a: (\mu_1 - µ_2) >(<) D_0)\\)
	**Two-tailed test**: \\(H_a: (\mu_1 - µ_2) ≠ D_0\\)

3. **Test Statistic:**

	\\[ t = \frac{(\bar{x}_1 - \bar{x}_2) - (\mu_1 - µ_2)} { \sqrt{s^2\bigg(\frac{1}{n_1}+\frac{1}{n_2}\bigg)}  }   \\]
 
 4. **Rejection Region:**
 
 	One-tailed test: \\(t > t_α \\) OR \\( t < -z_α\\)  
	Two-tailed test: \\(t > t_{α/2} \\) OR \\(z t -t_{α/2}\\)  
	
The **critical values** of `t`, \\(t_\alpha\\) and \\(t_{\alpha/2}\\) are based on \\((n_1 + n_2 - 2) = df \\) *degrees of freedom*. These tabulated values can be found using Table 4 of Appendix 1

**Assumption:** The sample is randomly and independently selected from normally distributed populations. *the variance of the populations \\(\sigma^2_1\\) and \\(\sigma^2_2\\) are equal.*

## Small-Sample (1 - α) 100% Confidence Interval for \\((\mu_1 - µ_2)\\) based on independent random samples. 

\\[ (\bar{x}_1 - \bar{x}_2) ± t_{\alpha/2}\sqrt{ s^2\bigg(\frac{1}{n_1} + \frac{1}{n_2}\bigg)} \\] 

where \\(s^2\\) is the *pooled estimate of* \\(\sigma^2\\).

**In general, this method is valid if \\( \frac{Larger → s^2}{Smaller → s^2} < 3 \\). If it is > 3 ...**

### If the difference between \\(s^2_1\\) and \\(s^2_2\\) is large use *Satterhwaite's Approximation*

If this is > 3 the pooled estimator for s² and the *sample variance is far from equal* it is no longer appropriate and the resulting **test statistic** is

\\[t = \frac{ (\bar{x}_1 - \bar{x}_2) - D_0 } { \sqrt{ \frac{s^2_1}{n_1} + \frac{s^2_2}{n_2} }} \\]

When the sample size is small, critical values for this statistic are found using degrees of freedom approximated by the formula 

\\[ df ≈ \frac { \bigg( \frac{s^2_1}{n_1} + \frac{s^2_2}{n_2}  \bigg)^2 } { \frac{(s^2_1/n_1)^2}{(n_1 -1)} + \frac{(s^2_2/n_2)^2}{(n_2 -1)} } \\]

## 10.5 Small-Sample Inference for the Difference Between two Means: A paired difference test. 

