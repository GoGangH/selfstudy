"""firstsite URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import include, path
import polls.views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', polls.views.home, name='home'),
    path('blog/<int:blog_id>', polls.views.detail, name='detail'), #<int:blog_id>는 path converter이라고 함 int는 정수형이라는 것 blog_id는 views.py에 있는 detail함수에 넘겨줄 인자
]
#path converter <type : 변수이름 >