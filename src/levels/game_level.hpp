#pragma once

/**
	Вопрос № ххх 
	
	На какую структуру данных похож класс GameLevel?
	- На односвязный список.

	В чём это выражается?
	- Класс хранит указатель на следующий элемент того же типа (GameLevel* next), образуя цепочку.
	
	Можно ли создавать экземпляры класса GameLevel и почему?
	- Нет, нельзя. Это абстрактный класс, так как он содержит чисто виртуальные методы (virtual ... = 0), которые должны быть реализованы в наследниках.
	
	В чём недостатки конструкции GameLevel?
	- Сильная связность: Текущий уровень жестко привязан к следующему (должен знать его тип для создания), что мешает легко менять порядок уровней.
*/

#include <cstddef>

#include "ui_factory.hpp"

namespace biv {
	class GameLevel {
		protected:
			UIFactory* ui_factory = nullptr;
			
			GameLevel* parent = nullptr;
			GameLevel* next = nullptr;

		protected:
			GameLevel(UIFactory*);

		public:
			virtual void restart();
			virtual bool is_final() const noexcept;

			virtual GameLevel* get_next() = 0;

		protected:
			void clear_data();

			virtual void init_data() = 0;
	};
}
