#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

enum class TaskStatus {
  NEW,
  IN_PROGRESS,
  TESTING,
  DONE,
};

TaskStatus Next(const TaskStatus& task_status) {
  return TaskStatus(static_cast<int>(task_status) + 1);
}

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

void EraseZeros(TasksInfo& tasks) {
  vector<TaskStatus> to_erase;

  for (const auto& [status, count] : tasks) {
    if (count == 0) {
      to_erase.push_back(status);
    }
  }

  for (const auto& status: to_erase) {
    tasks.erase(status);
  }
}

class TeamTasks {
 public:
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    return team_tasks.at(person);
  };

  void AddNewTask(const string& person) {
    team_tasks[person][TaskStatus::NEW]++;
  };

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
    try {
      TasksInfo untouched_tasks;
      TasksInfo performed_tasks;
      TasksInfo& person_tasks = team_tasks.at(person);

      for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
        performed_tasks[Next(status)] = min(person_tasks[status], task_count);
        task_count -= performed_tasks[Next(status)];
      }

      for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
        untouched_tasks[status] = person_tasks[status] - performed_tasks[Next(status)];
        person_tasks[status] = performed_tasks[status] + untouched_tasks[status];
      }

      person_tasks[TaskStatus::DONE] += performed_tasks[TaskStatus::DONE];

      EraseZeros(performed_tasks);
      EraseZeros(untouched_tasks);
      EraseZeros(person_tasks);

      return make_tuple(performed_tasks, untouched_tasks);
    } catch (out_of_range& e) {
      return make_tuple(TasksInfo{}, TasksInfo{});
    }
  };

 private:
  map<string, TasksInfo> team_tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" << ", "
       << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" << ", "
       << tasks_info[TaskStatus::TESTING] << " tasks are being tested" << ", "
       << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}