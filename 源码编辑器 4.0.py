import sys
from PyQt5.QtCore import Qt, QUrl
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QToolBar, QLineEdit, QPushButton
)
from PyQt5.QtWebEngineWidgets import QWebEngineView, QWebEngineUrlRequestInterceptor


class CustomUrlInterceptor(QWebEngineUrlRequestInterceptor):
    """自定义 URL 拦截器，限制只能访问指定网站"""
    def __init__(self, allowed_domain):
        super().__init__()
        self.allowed_domain = allowed_domain  # 允许的域名（如 "kitten4.codemao.cn"）

    def interceptRequest(self, info):
        """拦截所有 URL 请求"""
        url = info.requestUrl().toString()
        # 检查 URL 是否属于允许的域名
        if not url.startswith(f"https://{self.allowed_domain}/") and \
           not url.startswith(f"http://{self.allowed_domain}/"):
            # 禁止访问其他网址，跳转到允许的主页
            info.redirect(QUrl(f"https://{self.allowed_domain}/"))


class RestrictedBrowser(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("编程猫专用浏览器")
        self.setGeometry(100, 100, 800, 600)  # 设置窗口位置和大小

        # -------------------- 创建组件 --------------------
        # 网页视图
        self.web_view = QWebEngineView()
        self.setCentralWidget(self.web_view)

        # 地址栏
        self.url_bar = QLineEdit()
        self.url_bar.setReadOnly(True)  # 禁止手动输入网址
        self.url_bar.returnPressed.connect(self.navigate_to_url)  # 回车键触发跳转（虽然不可编辑）

        # 前进/后退按钮
        self.toolbar = QToolBar()
        self.addToolBar(self.toolbar)
        self.back_btn = QPushButton("←")
        self.forward_btn = QPushButton("→")
        self.reload_btn = QPushButton("↻")
        self.toolbar.addWidget(self.back_btn)
        self.toolbar.addWidget(self.forward_btn)
        self.toolbar.addWidget(self.reload_btn)
        self.toolbar.addWidget(self.url_bar)

        # -------------------- 功能绑定 --------------------
        self.back_btn.clicked.connect(self.web_view.back)
        self.forward_btn.clicked.connect(self.web_view.forward)
        self.reload_btn.clicked.connect(self.web_view.reload)

        # -------------------- 初始化配置 --------------------
        self.allowed_domain = "kitten4.codemao.cn"  # 允许的域名
        self.init_web_engine()
        self.load_initial_url()

    def init_web_engine(self):
        """初始化 Web 引擎配置"""
        settings = self.web_view.settings()
        settings.setAttribute(settings.JavascriptEnabled, True)  # 允许 JavaScript

        # 设置 URL 拦截器（限制访问域名）
        interceptor = CustomUrlInterceptor(self.allowed_domain)
        self.web_view.page().setUrlRequestInterceptor(interceptor)

    def load_initial_url(self):
        """加载初始网址"""
        url = QUrl(f"https://{self.allowed_domain}/")
        self.web_view.setUrl(url)
        self.update_url_bar(url)

    def navigate_to_url(self):
        """跳转至指定网址（虽然地址栏不可编辑，此函数用于演示）"""
        url = QUrl(self.url_bar.text())
        if url.isValid():
            self.web_view.setUrl(url)

    def update_url_bar(self, url):
        """更新地址栏显示"""
        self.url_bar.setText(url.toString())


if __name__ == "__main__":
    app = QApplication(sys.argv)
    browser = RestrictedBrowser()
    browser.show()
    sys.exit(app.exec_())
