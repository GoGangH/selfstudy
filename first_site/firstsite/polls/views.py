from tracemalloc import get_object_traceback
from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import Blog

def home(request):
    blogs=Blog.objects
    return render(request, 'home.html', {'blogs':blogs}) #블로그 정보 렌더링

def detail(request, blog_id):
    blog_detail = get_object_or_404(Blog, pk=blog_id) #객체 불러오기 있지도 않은 객체 불러오면 404에러 발생 pk는 primary key의 약자
    return render(request, 'detail.html', {'blog':blog_detail})
    #render(request, template_name(불러오고 싶은 템플릿), context(원하던 인자, view에서 사용하던 파이썬 변수 html로 넘기기))