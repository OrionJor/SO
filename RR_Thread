# Round-Robin com thread



from collections import deque, defaultdict
import threading
from threading import Thread
import time
from time import sleep
import random

def my_xrange(i, job_id):
	cur = 0
	while cur < i: 
		yield cur
		cur+=1

class Job(object):
	def __init__(self, job_func, kwargs, job_Prioridade, job_id = None):
		self.job = job_func(**kwargs)
		self.Prioridade = job_Prioridade
		self.id = job_id if job_id else random.randint(1, 10)
		self.num_times_run = 0
		self.time_taken = 0
		self.done = False

	def get_job_statistics(self):
		return (self.num_times_run, self.time_taken/self.num_times_run if self.num_times_run != 0 else 0)
	def run(self):
		print('executando job id {} e Prioridade {}'.format(self.id, self.Prioridade))
		now = time.time()
		try:
			next(self.job)
		except StopIteration:
			self.done = True
		self.time_taken += time.time() - now
		self.num_times_run+=1


class Scheduler(object):
	def __init__(self, tasks):
		self.waiting_tasks = deque(tasks)
		self.finished_tasks = []
		self.id_to_stats = {}

	def run_scheduled_jobs(self):
		# enquanto há empregos para processar
		while len(self.waiting_tasks) > 0:
			# escolha um emprego do topo
			current_task = self.waiting_tasks.popleft()
			#  execute a tarefa até que ela produza
			sleep(1)
			assert not current_task.done #  porque sempre que uma tarefa é feita, nunca a adicionamos de volta à fila de tarefas em espera
			current_task.run() 
			if not current_task.done:
				self.waiting_tasks.append(current_task)
			else:
				self.finished_tasks.append(current_task)
				print('job id {} just finished'.format(current_task.id))
		
		self.id_to_stats = {job_id: stats for job_id, stats in [(job.id, job.get_job_statistics()) for job in self.finished_tasks]}

	
	# adiciona os jobs ou seja os processos
	def add_jobs(self, num_jobs):
		print('adicionado {} jobs'.format(num_jobs))
		priorites = [1, 2, 3]
		new_jobs = [Job(my_xrange, {'i': 2, 'job_id': 6 + i},
			job_Prioridade=priorites[random.randint(0, len(priorites)-1)]) for i in range(num_jobs)]
		for job in new_jobs:
			print('adicionado o job id {} and Prioridade {}'.format(job.id, job.Prioridade))
			self.waiting_tasks.append(job)
			sleep(1)

	def print_job_stats(self):
		print('\n'.join(["job  id {} ran {} timpo de tarefa {} por execução".format(id, tup[0], tup[1]) 
			for id, tup in self.id_to_stats.items()]))

if __name__ == '__main__':
	generator = my_xrange(1, 1)
	try:
		while True:
			print(next(generator))
	except StopIteration:
		print("Ativo")
	priorites = [1, 2, 3]
	tasks = [Job(my_xrange, {'i': 2, 'job_id': i},
		job_Prioridade=priorites[random.randint(0, len(priorites)-1)]) for i in range(3)]
	scheduler = Scheduler(tasks)
	task_runner = Thread(target = scheduler.run_scheduled_jobs, name = 'corredor de tarefas')
	job_adder = Thread(target = scheduler.add_jobs, name = 'job-adicionando', kwargs ={'numero_jobs': 5})
	threads = [task_runner, job_adder]
	for thread in threads:
		thread.start()
	for thread in threads:
		thread.join()
	scheduler.print_job_stats()
