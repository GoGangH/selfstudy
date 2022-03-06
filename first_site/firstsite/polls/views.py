from django.http import HttpResponse
from django.shortcuts import render
from .models import Blog

def home(request):
    blogs=Blog.objects
    return render(request, 'home.html', {'blogs':blogs}) #블로그 정보 렌더링