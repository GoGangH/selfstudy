from tracemalloc import get_object_traceback
from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import Blog

def home(request):
    blogs=Blog.objects
    return render(request, 'home.html', {'blogs':blogs}) #블로그 정보 렌더링

def detail(request, blog_id):
    blog_detail = get_object_or_404(Blog, pk=blog_id)
    return render(request, 'detail.html', {'blog':blog_detail})
    #이게 뜻하는 바 알아보기