# biological-age-calculator
A computational tool designed to calculate comparative biological age based on physiological and lifestyle biomarkers.
# Comprehensive Biological Age & Biomarker Computational Pipeline 

##  Technical Project Overview
This production-ready C pipeline implements a multi-parametric assessment framework to compute, normalize, and evaluate human cellular aging profiles against chronological age. 

By modeling interactions between structural variables, lifestyle stressors, metabolic outputs, and pathobiological comorbidities, the system calculates a deterministic **Biological Age Index**. Additionally, it compiles dynamically adjusted dietary interventions based on targeted clinical risk vectors.

---

##  Algorithmic Architecture & Biomarker Mathematical Models

The application is engineered with structural modularity, delegating biological calculations into isolated mathematical domains to prevent data skewing:

### 1. Telomere Length Degradation Model (`calculateTelomere`)
This function estimates relative telomere base-pair preservation by applying structural degradation coefficients to lifestyle hazards:

$$TL = 8000 - (\text{Age} \times 25) - (\text{Smoker} \times 600) - (\text{SleepDeficit} \times 150) + (\text{Exercise} \times 40) - (\text{Comorbidities} \times 500)$$

* **Bioinformatics Implementation:** Sleep duration is normalized against a baseline human recovery threshold (8.0 hours). Chronic sleep deficits simulate accelerated replicative senescence, while localized comorbidity counts act as compounding cellular stress multipliers.

### 2. Genomic Damage Index (`calculateDNA`)
Models structural DNA damage accumulation by assessing oxidative stress and systemic inflammatory triggers:
* **Bioinformatics Implementation:** The index synthesizes Body Mass Index (BMI) calculations with pathological states, multiplying pathological loads by a sharp weighting constant ($\times 600$) to reflect real-world genomic degradation seen in chronic metabolic disease vectors.

### 3. Biological Composition Index (`calculateBCI`)
Computes an individual’s systemic cellular health and resilience score by contrasting physical activity and restorative sleep metrics against adipose tissue strain (BMI).

### 4. Consolidated Biological Age Assessment Matrix (`calculateBioAge`)
Integrates all sub-indices into a centralized aging evaluation formula:

$$\text{BioAge} = \text{Age} + \left(\frac{DD}{180}\right) + (\text{Comorbidities} \times 3.5) + \left(\frac{8000 - TL}{1500}\right) - \left(\frac{BCI}{90}\right)$$

* **Boundary Handling:** Implements a strict algorithmic floor constraint (`if (bioAge < p.age) bioAge = p.age;`) to ensure that calculated physiological values remain mathematically grounded within realistic baseline biological boundaries.

---

##  Code Architecture & Execution Flow

* **Custom Data Typing (`struct Person`):** Consolidates primary primitive data tracking variables (`int`, `float`, and multidimensional `char` arrays) within a unified stack memory block, ensuring high localization and low cache-miss latency.
* **Defensive User Input Parsing (`inputDiseases`):** Implements a selection array verification matrix (`selected[option - 1] == 0`) to enforce strict input data validation. This logic bounds options between values 1–7 and blocks redundant, multi-entry allocation bugs.
* **Dynamic String Operations (`showDiet`):** Leverages safe, direct memory-controlled string comparisons via `strcmp()` to evaluate active multi-comorbidity tracking nodes, mapping individual pathology strings to isolated, expert-validated nutritional protocols.

---

##  Technologies Used & Technical Stack
* **Core Languages:** C (Procedural logic implementation)
* **Methodologies:** Modular Programming, Dynamic Data Validation, Structural Data Mapping
* **Development Environment:** Local Compilers, Git versioning controls

---

##  Execution & Biological Logic Output Example

### Diagnostic Runtime Pipeline Trace:
```text
Select disease:
1. Diabetes
2. Hypertension
3. Heart Disease
Enter choice (1-7): 1
Add more? (1=Yes, 0=No): 0

===== HEALTH REPORT =====
Name: Hiba Khan
Actual Age: 20
Biological Age: 24
Aging faster by 4 years

===== DIET PLAN BASED ON DISEASES =====
For Diabetes, take:
- Low sugar diet
- Whole grains
- Avoid sweets

===== FINAL GENERAL DIET =====
- Follow all disease-specific diets strictly
- Avoid sugar, salt, and fried food
- Eat natural foods and stay hydrated
