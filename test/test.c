#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 10 // 种群大小
#define CHROMOSOME_LENGTH 10 // 染色体长度
#define MAX_GENERATIONS 100 // 最大迭代次数
#define MUTATION_RATE 0.1 // 突变率

// 染色体结构体
typedef struct {
    int genes[CHROMOSOME_LENGTH];
    int fitness;
} Chromosome;

// 初始化种群
void initializePopulation(Chromosome* population) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < CHROMOSOME_LENGTH; j++) {
            population[i].genes[j] = rand() % 2; // 随机生成0或1
        }
        population[i].fitness = 0;
    }
}

// 计算个体适应度
void calculateFitness(Chromosome* population) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        population[i].fitness = 0;
        for (j = 0; j < CHROMOSOME_LENGTH; j++) {
            population[i].fitness += population[i].genes[j];
        }
    }
}

// 选择交配的个体
void selectParents(Chromosome* population, Chromosome* parents) {
    int i;
    for (i = 0; i < POPULATION_SIZE / 2; i++) {
        int parent1 = rand() % POPULATION_SIZE;
        int parent2 = rand() % POPULATION_SIZE;
        if (population[parent1].fitness > population[parent2].fitness) {
            parents[i] = population[parent1];
        } else {
            parents[i] = population[parent2];
        }
    }
}

// 交叉产生新的个体
void crossover(Chromosome* parents, Chromosome* offspring) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE / 2; i++) {
        int crossoverPoint = rand() % (CHROMOSOME_LENGTH - 1) + 1;
        for (j = 0; j < crossoverPoint; j++) {
            offspring[i].genes[j] = parents[i].genes[j];
        }
        for (j = crossoverPoint; j < CHROMOSOME_LENGTH; j++) {
            offspring[i].genes[j] = parents[i+1].genes[j];
        }
    }
}

// 突变
void mutate(Chromosome* offspring) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE / 2; i++) {
        for (j = 0; j < CHROMOSOME_LENGTH; j++) {
            if ((float)rand() / RAND_MAX < MUTATION_RATE) {
                offspring[i].genes[j] = 1 - offspring[i].genes[j];
            }
        }
    }
}

// 替换种群
void replacePopulation(Chromosome* population, Chromosome* offspring) {
    int i;
    for (i = 0; i < POPULATION_SIZE / 2; i++) {
        population[i] = offspring[i];
    }
}

// 打印种群信息
void printPopulation(Chromosome* population) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        printf("Individual %d: \t", i);
        for (j = 0; j < CHROMOSOME_LENGTH; j++) {
            printf("%d ", population[i].genes[j]);
        }
        printf("\tFitness: %d\n", population[i].fitness);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // 设置随机种子

    Chromosome population[POPULATION_SIZE];
    Chromosome parents[POPULATION_SIZE / 2];
    Chromosome offspring[POPULATION_SIZE / 2];

    initializePopulation(population);
    calculateFitness(population);

    int generation;
    for (generation = 1; generation <= MAX_GENERATIONS; generation++) {
        printf("Generation %d\n", generation);

        selectParents(population, parents);
        crossover(parents, offspring);
        mutate(offspring);
        replacePopulation(population, offspring);

        calculateFitness(population);
        printPopulation(population);
    }

    return 0;
}