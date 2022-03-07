from django.db import models
'''
class [앱이름(Account)](models.Model):
	name = models.CharField(max_length=50)
	create_at = models.DataTimeField(auto_now=True)

	class Meta:
		db_table='[앱 이름]'
'''
from django.db import models

class Blog(models.Model): #블로그 테이블 생성
    title = models.CharField(max_length=200) #제목
    pub_date=models.DateField('date published') #작성 날짜
    body=models.TextField() #글의 내용

    def __str__(self):
        return self.title 

    def summary(slef):
        return self.body[:200]
    #외부에서 보이는 타이틀 명 변경
# Create your models here.
